#!/bin/bash
# mkcdi.sh — Dreamcast selfboot CDI builder for Linux
# Non-interactive CLI port of lzlite/Lazyboot pipeline (lazyboot).
#
# Usage: ./mkcdi.sh [options]
# See --help for full option list.

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
SYSTEM_DIR="$SCRIPT_DIR/system"
PRECON_DIR="$SYSTEM_DIR/precon"

# ── Architecture detection ──────────────────────────────────────────────────
ARCH=""
case "$(uname -m)" in
    aarch64|arm64) ARCH="-arm64" ;;
esac

tool() {
    local t="$SYSTEM_DIR/$1$ARCH"
    if [ -x "$t" ]; then echo "$t"; return; fi
    if [ -n "$ARCH" ] && [ -f "$SYSTEM_DIR/$1.py" ]; then echo "$SYSTEM_DIR/$1.py"; return; fi
    if [ -x "$SYSTEM_DIR/$1" ]; then echo "$SYSTEM_DIR/$1"; return; fi
    if [ -f "$SYSTEM_DIR/$1.py" ]; then echo "$SYSTEM_DIR/$1.py"; return; fi
    echo ""
}

# ── Defaults ─────────────────────────────────────────────────────────────────
ROMNAME=""
LBA=11702
BINARY="1ST_READ.BIN"
DATA_DIR="./data"
OUTPUT=""
SORT_FILE=""
QUIET=false
FAST=false   # use cdibuilder (fast, no ECC) instead of cdi4dc
DUMMY=false  # pad disc with dummy file to optimal capacity (LBA 11702 only)
NOHACK=false # skip hack4/binhack32/bincon (for pre-patched binaries)
LOGO=false   # inject logo into IP.BIN (logo.mr for Katana, wince.mr for WinCE)
TIMESTAMP=false  # append build timestamp to output filename

# Helper: run command, suppressing output when --quiet
run() {
    if $QUIET; then
        "$@" >/dev/null 2>&1
    else
        "$@"
    fi
}

# ── Source config file if present ────────────────────────────────────────────
if [ -f "$SCRIPT_DIR/mkcdi.conf" ]; then
    source "$SCRIPT_DIR/mkcdi.conf"
fi

# ── Usage ────────────────────────────────────────────────────────────────────
usage() {
    cat <<EOF
Usage: $0 [options]

Options:
  --romname NAME    Game name / volume label (required)
  --lba LBA         Session 2 LBA (default: 11702 for audio/data, 45000 for data/data)
  --binary BIN      Boot binary filename (default: 1ST_READ.BIN)
  --data-dir DIR    Directory with game data (default: ./data)
  --output CDI      Output CDI filename (default: NAME.cdi)
  --sort FILE       Sort file for mkisofs (optional)
  --kos             KallistiOS mode: skip hack4/binhack, use kos.bin IP.BIN
  --nohack          Skip hack4/binhack32/bincon (for pre-patched binaries)
  --logo            Inject logo.mr into IP.BIN (Katana only; WinCE always gets wince.mr)
  --dummy           Pad disc to optimal capacity (LBA 11702 only)
  --fast            Fast mode: use cdibuilder (no ECC, for quick testing)
  --timestamp       Append build timestamp to output filename
  --quiet           Suppress info messages

Examples:
  $0 --romname "My Game" --data-dir ./data
  $0 --romname "Game" --lba 45000 --data-dir ./data
  $0 --romname "Game" --binary 0WINCEOS.BIN --data-dir ./data
EOF
    exit 0
}

# ── Parse CLI args ──────────────────────────────────────────────────────────
while [[ $# -gt 0 ]]; do
    case "$1" in
        --romname)     ROMNAME="$2"; shift 2 ;;
        --lba)         LBA="$2"; shift 2 ;;
        --binary)      BINARY="$2"; shift 2 ;;
        --data-dir)    DATA_DIR="$2"; shift 2 ;;
        --output)      OUTPUT="$2"; shift 2 ;;
        --sort)        SORT_FILE="$2"; shift 2 ;;
        --kos)         KOS=true; shift ;;
        --nohack)      NOHACK=true; shift ;;
        --logo)        LOGO=true; shift ;;
        --timestamp)   TIMESTAMP=true; shift ;;
        --dummy)       DUMMY=true; shift ;;
        --fast)        FAST=true; shift ;;
        --quiet)       QUIET=true; shift ;;
        -h|--help)     usage ;;
        *) echo "Unknown option: $1"; usage ;;
    esac
done

# ── Validate ─────────────────────────────────────────────────────────────────
if [ -z "$ROMNAME" ]; then
    echo "Error: --romname is required"
    usage
fi

if [ -z "$OUTPUT" ]; then
    OUTPUT="${ROMNAME}.cdi"
fi

# Resolve data dir to absolute path
_ORIG_DATA_DIR="$DATA_DIR"
DATA_DIR="$(cd "$DATA_DIR" 2>/dev/null && pwd)" || {
    echo "Error: data directory '$_ORIG_DATA_DIR' not found"
    exit 1
}

# ── KOS detection: if exactly one .elf file exists, convert to 1ST_READ.BIN ─
KOS=false
ELF_COUNT=$(find "$DATA_DIR" -maxdepth 1 -name "*.elf" -type f | wc -l)

if [ "$ELF_COUNT" -eq 1 ]; then
    KOS=true
    ELF_FILE=$(find "$DATA_DIR" -maxdepth 1 -name "*.elf" -type f | head -1)
    $QUIET || echo "==> KOS ELF detected: $(basename "$ELF_FILE")"

    ELF2BIN="$SYSTEM_DIR/elf2bin$ARCH"
    if [ -x "$ELF2BIN" ]; then
        $QUIET || echo "  elf2bin (ELF -> scrambled 1ST_READ.BIN)"
        run "$ELF2BIN" "$ELF_FILE" "$DATA_DIR/1ST_READ.BIN"
    else
        # Fallback: objcopy + scramble
        SCRAMBLE=$(tool scramble)
        [ -z "$SCRAMBLE" ] && [ -x "$SYSTEM_DIR/scramble" ] && SCRAMBLE="$SYSTEM_DIR/scramble"
        if [ -z "$SCRAMBLE" ]; then
            echo "Error: scramble not found, cannot convert ELF"
            exit 1
        fi
        $QUIET || echo "  objcopy -O binary -> unscrambled.bin"
        objcopy -O binary "$ELF_FILE" /tmp/mkcdi_unscrambled.bin 2>/dev/null || {
            $QUIET || echo "  (Python ELF fallback)"
            python3 -c "
import struct
data = open('$ELF_FILE','rb').read()
is32 = data[4] == 1
e_phoff = struct.unpack_from('<I' if is32 else '<Q', data, 0x1c if is32 else 0x20)[0]
e_phentsize, e_phnum = struct.unpack_from('<HH', data, 0x2a if is32 else 0x36)
segs = []
for i in range(e_phnum):
    off = e_phoff + i * e_phentsize
    if struct.unpack_from('<I', data, off)[0] == 1:
        _, p_off2, p_va, _, p_fs, p_ms = struct.unpack_from('<IIIIII', data, off)
        segs.append((p_off2, p_va, p_fs, p_ms))
min_v = min(s[1] for s in segs)
max_v = max(s[1] + s[3] for s in segs)
buf = bytearray(max_v - min_v)
for p_off2, p_va, p_fs, p_ms in segs:
    buf[p_va - min_v : p_va - min_v + p_fs] = data[p_off2 : p_off2 + p_fs]
open('/tmp/mkcdi_unscrambled.bin','wb').write(buf)
"
        }
        $QUIET || echo "  scramble -> 1ST_READ.BIN"
        run "$SCRAMBLE" /tmp/mkcdi_unscrambled.bin "$DATA_DIR/1ST_READ.BIN"
        rm -f /tmp/mkcdi_unscrambled.bin
    fi
    rm -f "$ELF_FILE"
    BINARY="1ST_READ.BIN"
elif [ "$ELF_COUNT" -gt 1 ]; then
    echo "Error: Multiple .elf files found in $DATA_DIR/. Keep only one."
    exit 1
fi

# Auto-detect binary: 0WINCEOS.BIN overrides default, else check if default exists
if [ -f "$DATA_DIR/0WINCEOS.BIN" ]; then
    BINARY="0WINCEOS.BIN"
fi
if [ ! -f "$DATA_DIR/$BINARY" ]; then
    echo "Error: boot binary '$BINARY' not found in $DATA_DIR/"
    exit 1
fi

# ── Build version ───────────────────────────────────────────────────────────
BUILD_VER=$(date +"%Y%m%d-%H%M%S")
$QUIET || echo "Build: $BUILD_VER"

# Apply timestamp if requested (overrides explicit --output, matches lazyboot)
if $TIMESTAMP; then
    OUTPUT="${ROMNAME}-${BUILD_VER}.cdi"
fi

# ── IP.BIN template ─────────────────────────────────────────────────────────
# lazyboot logic: boots2 for WinCE, boots1 for Katana, boots3 for KOS
# Our precon equivalents: wince.bin, katana.bin, kos.bin, lodoss-5167.bin
if [ "$BINARY" = "1NOSDC.BIN" ]; then
    # lodoss edge case — always replace IP.BIN
    cp "$PRECON_DIR/lodoss-5167.bin" "$DATA_DIR/IP.BIN"
    $QUIET || echo "IP.BIN: lodoss-5167 template"
elif $KOS && [ ! -f "$DATA_DIR/IP.BIN" ]; then
    cp "$PRECON_DIR/kos.bin" "$DATA_DIR/IP.BIN"
    $QUIET || echo "IP.BIN: kos template (boots3)"
elif [ ! -f "$DATA_DIR/IP.BIN" ]; then
    if [ "$BINARY" = "0WINCEOS.BIN" ]; then
        cp "$PRECON_DIR/wince.bin" "$DATA_DIR/IP.BIN"
        $QUIET || echo "IP.BIN: wince template (boots2)"
    else
        cp "$PRECON_DIR/katana.bin" "$DATA_DIR/IP.BIN"
        $QUIET || echo "IP.BIN: katana template (boots1)"
    fi
else
    $QUIET || echo "IP.BIN: using existing"
fi

# ── hack4: unprotect + LBA ────────────────────
if $KOS || $NOHACK; then
    $QUIET || echo "==> Skipping hack4/binhack ($($KOS && echo 'KOS' || echo '--nohack'))"
else
$QUIET || echo "Patching binary..."
HACK4=$(tool hack4)

if [ -n "$HACK4" ]; then
    # Collect .BIN files (case-sensitive on Linux), exclude IP.BIN
    BIN_FILES=()
    for f in "$DATA_DIR"/*.BIN; do
        [ -f "$f" ] || continue
        [ "$(basename "$f")" = "IP.BIN" ] && continue
        BIN_FILES+=("$f")
    done

    if [ ${#BIN_FILES[@]} -gt 0 ]; then
        $QUIET || echo "  hack4 unprotect..."
        if [ -f "$HACK4" ] && [[ "$HACK4" == *.py ]]; then
            run python3 "$HACK4" -w -p "${BIN_FILES[@]}"
        else
            run "$HACK4" -w -p "${BIN_FILES[@]}"
        fi

        $QUIET || echo "  hack4 LBA -> $LBA..."
        if [ -f "$HACK4" ] && [[ "$HACK4" == *.py ]]; then
            run python3 "$HACK4" -w -3 -n "$LBA" "${BIN_FILES[@]}"
        else
            run "$HACK4" -w -n "$LBA" "${BIN_FILES[@]}"
        fi
    fi
else
    echo "Warning: hack4 not found, skipping binary patching"
fi

# ── WinCE: bincon before binhack ────────────────────
if [ "$BINARY" = "0WINCEOS.BIN" ]; then
    BINCON=$(tool bincon)
    if [ -n "$BINCON" ] && [ -f "$DATA_DIR/0WINCEOS.BIN" ] && [ -f "$DATA_DIR/IP.BIN" ]; then
        $QUIET || echo "  bincon (WinCE -> Katana-style)..."
        if [ -f "$BINCON" ] && [[ "$BINCON" == *.py ]]; then
            run python3 "$BINCON" "$DATA_DIR/0WINCEOS.BIN" "$DATA_DIR/0WINCEOS.BIN" "$DATA_DIR/IP.BIN"
        else
            run "$BINCON" "$DATA_DIR/0WINCEOS.BIN" "$DATA_DIR/0WINCEOS.BIN" "$DATA_DIR/IP.BIN"
        fi
    fi
fi

# ── binhack: patch IP.BIN + binary ─────────────
BHACK=$(tool binhack32)

if [ -n "$BHACK" ] && [ -f "$DATA_DIR/IP.BIN" ]; then
    TMPDIR=$(mktemp -d)
    trap "rm -rf $TMPDIR" EXIT

    $QUIET || echo "  binhack32 $BINARY IP.BIN LBA=$LBA..."

    if [ -f "$BHACK" ] && [[ "$BHACK" == *.py ]]; then
        run python3 "$BHACK" "$DATA_DIR/$BINARY" "$DATA_DIR/IP.BIN" "$LBA" --output-dir "$TMPDIR" --quiet
    else
        run "$BHACK" "$DATA_DIR/$BINARY" "$DATA_DIR/IP.BIN" "$LBA" --output-dir "$TMPDIR" --quiet
    fi

    # Move hacked files back to data/
    if [ -f "$TMPDIR/$BINARY" ]; then
        mv "$TMPDIR/$BINARY" "$DATA_DIR/$BINARY"
    fi
    if [ -f "$TMPDIR/IP.BIN" ]; then
        mv "$TMPDIR/IP.BIN" "$DATA_DIR/IP.BIN"
    fi
else
    $QUIET || echo "  Warning: binhack32 not found, skipping IP.BIN patching"
fi
fi  # end of KOS skip block

# ── WinCE logo: inject after binhack (so bootstrap data doesn't overwrite it) ─
if [ "$BINARY" = "0WINCEOS.BIN" ]; then
    if [ -x "$SYSTEM_DIR/logoinsert$ARCH" ] && [ -f "$SYSTEM_DIR/wince.mr" ]; then
        $QUIET || echo "  logoinsert (inject wince.mr)..."
        run "$SYSTEM_DIR/logoinsert$ARCH" "$SYSTEM_DIR/wince.mr" "$DATA_DIR/IP.BIN"
    fi
fi

# ── Katana logo: optional, inject after binhack ──────────────────────────────
if $LOGO && [ "$BINARY" != "0WINCEOS.BIN" ]; then
    if [ -x "$SYSTEM_DIR/logoinsert$ARCH" ] && [ -f "$SYSTEM_DIR/logo.mr" ]; then
        $QUIET || echo "  logoinsert (inject logo.mr)..."
        run "$SYSTEM_DIR/logoinsert$ARCH" "$SYSTEM_DIR/logo.mr" "$DATA_DIR/IP.BIN"
    fi
fi

# ── mkisofs ────────────────────────────────────────
ISO_FILE="${OUTPUT%.cdi}.iso"
SORT_ARG=""
if [ -n "$SORT_FILE" ] && [ -f "$SORT_FILE" ]; then
    SORT_ARG="-sort $SORT_FILE"
fi

# Handle dummy/padding (Lazyboot doomer logic)
DUMMY_ARG=""
EXC_ARG=""
HIDE_ARG=""

if $DUMMY; then
    # Remove stale dummy from previous runs
    rm -f "$DATA_DIR/0.0"
    if [ "$LBA" -gt 11702 ]; then
        echo "Note: --dummy disabled for LBA $LBA (requires LBA 11702)"
    else
        DATASIZE=$(du -sk "$DATA_DIR" 2>/dev/null | cut -f1)
        DATASIZE=$((DATASIZE * 1024))
        DISC_SIZE=712841213  # 80min CD
        MAXSIZE=$((DISC_SIZE - 7340032))
        DUMMY_FILE=$((MAXSIZE - DATASIZE))

        if [ "$DUMMY_FILE" -gt 0 ]; then
            $QUIET || echo "  Data: $((DATASIZE / 1024 / 1024)) MB, Dummy: $((DUMMY_FILE / 1024 / 1024)) MB"
            if [ -x "$SYSTEM_DIR/doomer" ]; then
                run "$SYSTEM_DIR/doomer" "$DUMMY_FILE" "$DATA_DIR/0.0"
            else
                # fallback: use dd
                dd if=/dev/zero of="$DATA_DIR/0.0" bs=1 count=0 seek="$DUMMY_FILE" 2>/dev/null
            fi
        else
            echo "Warning: --dummy: data already fills disc ($((DATASIZE / 1024 / 1024)) MB)"
        fi
    fi
fi

if [ -f "$DATA_DIR/0.0" ]; then
    DUMMY_ARG="-hide 0.0 -hide-joliet 0.0"
fi
if [ -f "$DATA_DIR/Desktop.ini" ]; then
    EXC_ARG="$EXC_ARG -m Desktop.ini"
fi
if [ -f "$DATA_DIR/Thumbs.db" ]; then
    EXC_ARG="$EXC_ARG -m Thumbs.db"
fi
if [ -f "$DATA_DIR/autorun.inf" ]; then
    HIDE_ARG="-hidden autorun.inf"
fi

$QUIET || echo "Creating ISO (LBA=$LBA)..."
MKISOFS=$(tool mkisofs)
if [ ! -x "$MKISOFS" ]; then
    MKISOFS="mkisofs"
fi

$QUIET || echo "  $MKISOFS -C 0,$LBA -V '$ROMNAME' -G data/IP.BIN -exclude IP.BIN -l -J -r -o $ISO_FILE $DATA_DIR"
run "$MKISOFS" -C "0,$LBA" -V "$ROMNAME" $SORT_ARG $DUMMY_ARG $EXC_ARG $HIDE_ARG -G "$DATA_DIR/IP.BIN" -exclude IP.BIN -l -J -r -o "$ISO_FILE" "$DATA_DIR"

# ── ISO → CDI ───────────────────────────────────────────────────────────────
$QUIET || echo "Converting ISO to CDI..."

if $FAST; then
    # --fast: cdibuilder (quick, no ECC, any LBA)
    CDIBUILDER=$(tool cdibuilder)
    $QUIET || echo "  cdibuilder -I $ISO_FILE -o $OUTPUT -l $LBA -t audio -V '$ROMNAME' (fast)"
    run "$CDIBUILDER" -I "$ISO_FILE" -o "$OUTPUT" -l "$LBA" -t audio -V "$ROMNAME"
else
    CDI4DC="$SCRIPT_DIR/cdi4dc"

    # cdi4dc (proper ECC/EDC) for audio/data at LBA 11702.
    # For other LBAs, fall back to cdibuilder.
    if [ "$LBA" = "11702" ] && [ -x "$CDI4DC" ]; then
        $QUIET || echo "  cdi4dc $ISO_FILE $OUTPUT (audio/data, LBA 11702)"
        run "$CDI4DC" "$ISO_FILE" "$OUTPUT"
    else
        if [ "$LBA" != "11702" ]; then
            echo "Note: LBA $LBA — cdi4dc only handles LBA 11702. Using cdibuilder."
        fi
        CDIBUILDER=$(tool cdibuilder)
        $QUIET || echo "  cdibuilder -I $ISO_FILE -o $OUTPUT -l $LBA -t audio -V '$ROMNAME'"
        run "$CDIBUILDER" -I "$ISO_FILE" -o "$OUTPUT" -l "$LBA" -t audio -V "$ROMNAME"
    fi
fi

# ── Cleanup ─────────────────────────────────────────────────────────────────
rm -f "$ISO_FILE"

echo ""
echo "Done: $OUTPUT"

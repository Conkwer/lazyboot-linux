# mkcdi-linux (beta)

Linux-Native CLI Selfboot Toolchain for Dreamcast

This is a headless, non-interactive CI/CD-ready port of the Lazyboot pipeline, designed
for AI-powered development and automated build loops. Traditional tools force you to
"click" or type through chains of Y/N prompts. This pipeline is purely declarative.
You provide the inputs, it provides the CDI.  

Also availible as a single (and portable) All-in-One binary in a cditools toolkit. See: [cditools](https://github.com/Conkwer/cditools/tree/main/mkcdi-portable-linux)  

The original Lazyboot toolchain was Windows-mostly and interactive. Most of its tools had
no Linux port or equivalent, so automation was pretty hard. This project fixes that:
everything runs non-interactively, with native Linux binaries for
x86-64 and aarch64, no Wine needed.

Also works on phones (aarch64), if you're crazy enough to build Dreamcast images on the go.  

Tested on x86-64 (Debian 12) and aarch64 (Snapdragon 625 via Termux + Debian proot). Should work on Armbian and similar glibc-based distros. Note: will not work on bare Termux (Android bionic libc + seccomp); use proot-distro Debian or a proper Linux environment.  

## Notes  
Sources for cdi4dc not included in this repo. 
[cdi4dc linux fork](https://github.com/Conkwer/img4dc) used for ISO→CDI conversion with proper ECC/EDC. Optional.  

## Quick start

```bash
./mkcdi.sh --romname mygame --data-dir ./data
```

This creates `mygame.cdi` as an Audio/Data image (LBA 11702) using cdi4dc with proper ECC/EDC.

## Requirements

- Linux x86-64 or aarch64 (binaries auto-detected)
- `genisoimage` or `mkisofs` (included wrapper falls back to system-installed)
- `python3` (for Python-based tool fallbacks)

## Usage

```
Usage: mkcdi.sh [options]

Options:
  --romname NAME    Game name / volume label (required)
  --lba LBA         Session 2 LBA (default: 11702 for audio/data, 45000 for data/data)
  --binary BIN      Boot binary filename (default: 1ST_READ.BIN)
  --data-dir DIR    Directory with game data (default: ./data)
  --output CDI      Output CDI filename (default: NAME.cdi)
  --sort FILE       Sort file for mkisofs (optional)
  --quiet           Suppress info messages
```

## Examples

```bash
# Standard Audio/Data image at LBA 11702 (default, uses cdi4dc with ECC)
./mkcdi.sh --romname mygame --data-dir ./mygame_data

# Custom LBA (falls back to cdibuilder — fast, no ECC, for testing)
./mkcdi.sh --romname mygame --lba 45000 --data-dir ./mygame_data

# Custom binary name (WinCE)
./mkcdi.sh --romname mygame --binary 0WINCEOS.BIN --data-dir ./mygame_data

# With sort file and custom output name
./mkcdi.sh --romname mygame --data-dir ./data --sort sortfile.str --output release.cdi

# Using a config file for defaults
cp mkcdi.conf.example mkcdi.conf
# Edit mkcdi.conf, then:
./mkcdi.sh --romname mygame
```

## Pipeline

### Katana (standard)
1. Detect boot binary and select IP.BIN template (katana / wince / lodoss-5167)
2. `hack4` — unprotect binary and patch LBA references
3. `binhack32` — hack IP.BIN + binary with boot sector data and LBA
4. `mkisofs` — create ISO with proper `-C 0,LBA` multisession parameters
5. `cdi4dc` — convert ISO to CDI with proper ECC/EDC (for LBA 11702)
   - Falls back to `cdibuilder` for non-11702 LBAs (fast, no ECC)

### WinCE (0WINCEOS.BIN detected)
1. `hack4` → `bincon` (WinCE→Katana conversion) → `binhack32` → `logoinsert` (inject wince.mr)
2. `mkisofs` → `cdi4dc` or `cdibuilder` (--fast)

### KallistiOS (ELF auto-detected or --kos)
1. `objcopy -O binary` (with Python fallback for SH-4 ELFs) → `scramble` → `1ST_READ.BIN`
2. Use `kos.bin` IP.BIN template
3. Skip hack4/binhack/bincon (KOS binaries are selfboot-ready)
4. `mkisofs` → `cdi4dc` or `cdibuilder` (--fast)

## CDI conversion tools

| Tool | ECC/EDC | LBA support | Use case |
|------|---------|-------------|----------|
| `cdi4dc` | Yes | 11702 only (audio/data) | Default — reliable, proper ECC |
| `cdibuilder` | No (fast) | Any | Fallback for non-11702 LBAs, quick testing |

cdi4dc is used by default (LBA 11702). For other LBAs (e.g., 45000 data/data),
the script falls back to cdibuilder with a warning — it's faster but skips ECC,
suitable for quick testing only.

## Directory structure

```
mkcdi-linux/
  mkcdi.sh              # Main pipeline script
  cdi4dc                # ISO→CDI converter (proper ECC/EDC)
  mkcdi.conf.example    # Example configuration
  system/
    hack4               # LBA patcher (binary)
    binhack32           # IP.BIN + binary hacker (binary, CLI)
    bincon              # WinCE binary converter
    scramble            # KOS ELF scrambler (future)
    mkisofs             # ISO creation tool (genisoimage wrapper)
    iso2cdi.py          # ISO→CDI converter (Python, fast, no ECC)
    cdibuilder          # ISO→CDI fallback (fast, no ECC)
    precon/             # IP.BIN templates
    src/                # Additional documentation
```

## Credits

| Tool | Author | Notes |
|------|--------|-------|
| `mkcdi.sh` / lzlite / Lazyboot | Conkwer | GPLv3 |
| `hack4` (C++/Python) | Conkwer | GPLv3; Inspired by kikuchan's original hack4 (2001); independent implementation |
| `binhack32` | FamilyGuy (v1.0.0.5, 2011-2014), SiZiOUS (optimization) | GPLv3; bugs fixed (tail, false CD001, stream failbit) |
| `bincon` (C) | unknown | GPLv3; original Windows binary |
| `bincon.py` | Conkwer | GPLv3; Python port of the original |
| `cdi4dc` | [big_fury]SiZiOUS (v0.5b, 2021) | GPLv3 |
| `cdibuilder` | Conkwer | GPLv3; C++ CDI builder, used with `--fast` or as fallback for non-11702 LBAs |
| `iso2cdi.py` | Conkwer | GPLv3; based on PSX-Planet script (unknown author) |
| `scramble` | Marcus Comstedt | Public Domain |
| `elf_parser` | finixbit (2018), Colton Pawielski (2022-2023) | MIT |
| `logoinsert` | Conkwer | GPLv3; simple MR logo injector |
| `doomer` | Conkwer | GPLv3; dummy/padding file creator |
| `elf2bin` | finixbit, Pawielski, Marcus Comstedt | Merges elf_parser (MIT) + scramble (Public Domain) into one CLI tool |
| `mkisofs` wrapper | J. Schilling / E. Youngdale | GPL; genisoimage |

## Building from source

See individual source files in `system/`. C/C++ sources compile with `g++` or `gcc`:

```bash
g++ -std=c++17 -O2 system/hack4.cpp -o system/hack4
g++ -std=c++17 -O2 system/binhack32-cli.cpp system/binhack.cpp -o system/binhack32 -Wno-narrowing
g++ -std=c++17 -O2 system/elf2bin.cpp system/elf_parser.cpp system/scramble.cpp -o system/elf2bin
g++ -std=c++17 -O2 system/logoinsert.cpp -o system/logoinsert
```

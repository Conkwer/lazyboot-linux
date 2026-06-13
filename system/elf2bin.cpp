// elf2bin — Extract binary from ELF and scramble for Dreamcast
#include "elf_parser.hpp"
#include "scramble.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input.elf> <output.bin>\n";
        return 1;
    }

    // Read ELF file
    std::ifstream elf_file(argv[1], std::ios::binary);
    if (!elf_file) {
        std::cerr << "Error opening: " << argv[1] << "\n";
        return 1;
    }
    std::vector<char> elf_data((std::istreambuf_iterator<char>(elf_file)),
                                std::istreambuf_iterator<char>());

    // Parse ELF
    auto parser_opt = elfparser::Parser::Load(elf_data);
    if (!parser_opt || !*parser_opt) {
        std::cerr << "Error parsing ELF\n";
        return 1;
    }

    // Get raw binary from segments
    std::vector<char> unscrambled;
    if (!(*parser_opt)->fill_bin(unscrambled) || unscrambled.empty()) {
        std::cerr << "Error extracting binary from ELF\n";
        return 1;
    }

    // Scramble
    std::vector<char> scrambled = scramble(unscrambled);

    // Write output
    std::ofstream out(argv[2], std::ios::binary);
    if (!out) {
        std::cerr << "Error writing: " << argv[2] << "\n";
        return 1;
    }
    out.write(scrambled.data(), scrambled.size());
    std::cout << "elf2bin: " << argv[1] << " -> " << argv[2]
              << " (" << scrambled.size() << " bytes)\n";
    return 0;
}

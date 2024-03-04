#include <iostream>
#include <tokenizer/Tokenizer.h>
#include <fstream>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::string full_string;
    std::fstream FILE(argv[1], std::ios::in);
    if (!FILE.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    } else {
        std::string buffer;
        while (std::getline(FILE, buffer)) {
            full_string.append(buffer + '\n');
        }
    }
    FILE.close();
    Tokenizer tokenizer;
    std::vector<Token> res = tokenizer.tokenize(full_string);
    for (const Token& t : res) {
            std::cout << "[" << t.token_type << "; \"" << t.lexem << "\"]" << std::endl;
    }
    return 0;
}
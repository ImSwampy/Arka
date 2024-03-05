#include <iostream>
#include <tokenizer/Tokenizer.h>
#include <fstream>
#include <utils/ReadFile.h>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::fstream FILE = std::fstream(argv[1], std::ios::in);
    std::vector<Token> res;

    if (FILE.is_open()) {
        Tokenizer tokenizer;
        res = read_lines_tokenize(FILE, tokenizer);
    } else {
        std::cerr << "cant open file: " << argv[1] << std::endl;
        return 0;
    };

    for (const Token t : res) {
            std::cout << "[" << t.token_type << "; \"" << t.lexem << "\"]" << std::endl;
    }
    return 0;
}
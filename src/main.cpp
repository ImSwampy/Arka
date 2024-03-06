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

    Tokenizer tokenizer;
    res = read_lines_tokenize(FILE, tokenizer);

    for (const Token t : res) {
            std::cout << "[" << TokenTypeNames.at(t.token_type) << "; \"" << t.lexem << "\"]" << "\n";
    }
    return 0;
}
#include <iostream>
#include <tokenizer/Tokenizer.h>
#include <fstream>
#include "utils/ReadFile.h"
#include "parser/Parser.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::fstream FILE = std::fstream(argv[1], std::ios::in);
    std::vector<Token> res;

    Tokenizer tokenizer;
    Parser parser;

    res = read_lines_tokenize(FILE, tokenizer);
    std::vector<std::vector<std::vector<Token>>> res2 = parser.identify_tokens(res);

    for (std::vector<std::vector<Token>> toks : res2) {
        std::cout << "{" << std::endl;
        for (std::vector<Token> tok : toks) {
            std::cout << "\t{" << std::endl;
            for (Token t : tok) {
                std::cout << "\t\t[" << t.token_type << "; " << t.lexem << "]" << std::endl;
            }
            std::cout << "\t}" << std::endl;
        }
        std::cout << "}" << std::endl;
    }

    return 0;
}
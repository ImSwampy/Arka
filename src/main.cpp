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

    Tokenizer tokenizer;
    Parser parser;

    std::vector<Token> res = read_lines_tokenize(FILE, tokenizer);
    Program res2 = parser.identify_tokens(res);

    for (Scope &scope : res2.get_program_content()) {
        std::cout << "{" << std::endl;
        for (auto _scope : scope.get_scope_content()) {
            std::cout << "\t{" << std::endl;
            if (typeid(_scope) == typeid(Scope))
                for (Token t: _scope.get_action_content()) {
                    std::cout << "\t\t[" << t.token_type << "; " << t.lexem << "]" << std::endl;
                } {
            }
            std::cout << "\t}" << std::endl;
        }
        std::cout << "}" << std::endl;
    }

    return 0;
}
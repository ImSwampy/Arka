#include "Parser.h"

void Parser::parse(std::vector<Token> &tokens) {

}

std::vector<std::vector<std::vector<Token>>> Parser::identify_tokens(std::vector<Token> tok) {
    std::vector<std::vector<std::vector<Token>>> program;
    std::vector<std::vector<Token>> scope;
    std::vector<Token> current_token_list;
    short int curly_braces_ratio = 0;
    for (size_t pos = 0; pos < tok.size(); pos++) {
        std::cout << pos << ": " << tok.at(pos).lexem << std::endl;
        Token curr = tok.at(pos);


        switch (curr.token_type) {
        case TokenTypes::Semicol:
            if (!current_token_list.empty()) {
                scope.push_back(current_token_list);
            }
            current_token_list.clear();
            break;

        case TokenTypes::L_Bracket:
            curly_braces_ratio++;
            break;

        case TokenTypes::R_Bracket:
            curly_braces_ratio--;
            program.push_back(scope);
            scope.clear();
            break;

        default:
            current_token_list.push_back(curr);
            break;
        }
    }
    
    if (curly_braces_ratio != 0) {
        if (curly_braces_ratio > 0) {
            std::cerr << "missing curly braces : '}'" << std::endl;
        } else {
            std::cerr << "missing curly braces : '{'" << std::endl;
        }

        exit(1);
    }

    return program;
}

void Parser::merge_token(std::vector<Token> tok) {

}

void Parser::consume_token(Token tok) {

}
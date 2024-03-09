#include "Parser.h"

void Parser::parse(std::vector<Token> &tokens) {

}

std::vector<std::vector<std::vector<Token>>> Parser::identify_tokens(std::vector<Token> tok) {
    std::vector<std::vector<std::vector<Token>>> program;
    std::vector<std::vector<Token>> scope;
    std::vector<Token> current_token_list;
    short int curly_braces_ratio = 0;
    for (size_t pos = 0; pos < tok.size(); pos++) {
        Token curr = tok.at(pos);
        
        if (curr.token_type != TokenTypes::R_Bracket && pos == tok.size()-1) {
            program.push_back(scope);
            break;
        }
        switch (curr.token_type) {
        case TokenTypes::Semicol:
            if (!current_token_list.empty()) {
                scope.push_back(current_token_list);
                current_token_list.clear();
            }
            break;

        case TokenTypes::L_Bracket:
            curly_braces_ratio++;
            break;

        case TokenTypes::R_Bracket:
            curly_braces_ratio--;
            scope.push_back(current_token_list);
            current_token_list.clear();
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
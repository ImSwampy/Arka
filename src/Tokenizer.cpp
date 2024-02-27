#include "Tokenizer.h"
#include "Types.h"
#include <stdexcept>
#include <iostream>

std::vector<Token> Tokenizer::tokenize(std::string code) {
    size_t pos = 0;
    std::vector<Token> result;

    while (pos < code.length()) {
        char current_char = code.at(pos);

        //check for numbers
        if (current_char >= '0' && current_char <= '9' || isdigit(current_char)) {
            std::string return_num(1, current_char);
            try {
                while (isdigit(code.at(pos++))) {
                    return_num.push_back(current_char);
                }
            } catch (...){}
            result.push_back(Token{NumberLiteral, return_num});
            continue;
        }

        if (isalpha(current_char)) {
            std::string return_str(1, current_char);
            try {
                while (isdigit(code.at(pos++))) {
                    return_str.push_back(current_char);
                }
            } catch (...){}

            result.push_back(Token{Identifier, return_str});
            continue;
        }

        //check for symbols
        switch (current_char) {
            case EQUAL: result.push_back(Token{Equal, "="}); break;
            case SLASH: result.push_back(Token{Slash, "/"}); break;
            case PLUS: result.push_back(Token{Plus, "+"}); break;
            case MINUS: result.push_back(Token{Minus, "-"}); break;
            case STAR: result.push_back(Token{Star, "*"}); break;
            case L_PAR: result.push_back(Token{L_Paren, "("}); break;
            case R_PAR: result.push_back(Token{R_Paren, ")"}); break;
            case L_BRAQ: result.push_back(Token{L_Bracket, "{"}); break;
            case R_BRAQ: result.push_back(Token{R_Bracket, "}"}); break;
            case SEMI_COLON: result.push_back(Token{Semicol, ";"}); break;
            case COLON: result.push_back(Token{Colon, ":"}); break;
            case HASHTAG: result.push_back(Token{Hashtag, "#"}); break;
            case SPACE: result.push_back(Token{Space, " "}); break;
            case ENDL: result.push_back(Token{Endl, "\n"}); break;
            default:
                std::cout << current_char << std::endl;
                break;
        }
    }

    return result;
}

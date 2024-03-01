#include "Tokenizer.h"
#include "Types.h"
#include <stdexcept>
#include <iostream>

#include "Tokenizer.h"


std::vector<Token> Tokenizer::tokenize(std::string code) {
    size_t pos = 0;
    std::vector<Token> result;

    while (pos < code.length()) {
        char current_char = code.at(pos);

        //check for numbers
        if (isdigit(current_char)) {
            std::string return_num(1, current_char);
            try {
                while (isdigit(code.at(++pos))) {
                    return_num.push_back(code.at(pos));
                }
            } catch (...){}
            result.push_back(Token{TokenTypeNames.find(NumberLiteral)->second, return_num});
            continue;
        }

        if (isalpha(current_char)) {
            std::string return_str(1, current_char);
            try {
                while (isdigit(code.at(pos++))) {
                    return_str.push_back(code.at(pos));
                }
            } catch (...){}

            result.push_back(Token{TokenTypeNames.find(Identifier)->second, return_str});
            continue;        }

        //check for symbols
        switch (current_char) {
            case EQUAL: result.push_back(Token{TokenTypeNames.find(Equal)->second, "="}); break;
            case SLASH: result.push_back(Token{TokenTypeNames.find(Slash)->second, "/"}); break;
            case PLUS: result.push_back(Token{TokenTypeNames.find(Plus)->second, "+"}); break;
            case MINUS: result.push_back(Token{TokenTypeNames.find(Minus)->second, "-"}); break;
            case STAR: result.push_back(Token{TokenTypeNames.find(Star)->second, "*"}); break;
            case L_PAR: result.push_back(Token{TokenTypeNames.find(L_Paren)->second, "("}); break;
            case R_PAR: result.push_back(Token{TokenTypeNames.find(R_Paren)->second, ")"}); break;
            case L_BRAQ: result.push_back(Token{TokenTypeNames.find(L_Bracket)->second, "{"}); break;
            case R_BRAQ: result.push_back(Token{TokenTypeNames.find(R_Bracket)->second, "}"}); break;
            case SEMI_COLON: result.push_back(Token{TokenTypeNames.find(Semicol)->second, ";"}); break;
            case COLON: result.push_back(Token{TokenTypeNames.find(Colon)->second, ":"}); break;
            case HASHTAG: result.push_back(Token{TokenTypeNames.find(Hashtag)->second, "#"}); break;
            case SPACE: result.push_back(Token{TokenTypeNames.find(Space)->second, " "}); break;
            case ENDL: result.push_back(Token{TokenTypeNames.find(Endl)->second, "\n"}); break;
            default:
                std::cout << current_char << std::endl;
                break;
        }
        pos++;
    }

    return result;
}

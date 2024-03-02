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

        if (isdigit(current_char)) {
            std::string return_num(1, current_char);
            try {
                while (isdigit(code.at(++pos))) {
                    return_num.push_back(code.at(pos));
                }
            } catch (...){}

            result.push_back(Token{"Digit", return_num});
            continue;
        }

        if (isalpha(current_char)) {
            std::string return_str(1, current_char);    
            try {
                while (isalpha(code.at(++pos))) {
                    return_str.push_back(code.at(pos));
                }
            } catch (...){}

            result.push_back(Token{"Identifier", return_str});  
            continue;        
        }

        //check for symbols
        switch (current_char) {
            case EQUAL: result.push_back(Token{"EQUAL", "="}); break;
            case SLASH: result.push_back(Token{"SLASH", "/"}); break;
            case PLUS: result.push_back(Token{"PLUS", "+"}); break;
            case MINUS: result.push_back(Token{"MINUS", "-"}); break;
            case STAR: result.push_back(Token{"STAR", "*"}); break;
            case L_PAR: result.push_back(Token{"L_PAR", "("}); break;
            case R_PAR: result.push_back(Token{"R_PAR", ")"}); break;
            case L_BRAQ: result.push_back(Token{"L_BRAQ", "{"}); break;
            case R_BRAQ: result.push_back(Token{"R_BRAQ", "}"}); break;
            case SEMI_COLON: result.push_back(Token{"SEMI_COLON", ";"}); break;
            case COLON: result.push_back(Token{"COLON", ":"}); break;
            case HASHTAG: result.push_back(Token{"HASHTAG", "#"}); break;
            case SPACE: result.push_back(Token{"SPACE", " "}); break;
            case ENDL: result.push_back(Token{"ENDL", "\n"}); break;
            default:
                result.push_back(Token{"UNDEFINED", std::string(1, current_char)});
                break;
        }
        pos++;
    }

    return result;
}

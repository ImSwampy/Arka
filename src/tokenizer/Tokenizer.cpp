#include <stdexcept>
#include <iostream>

#include "Types.h"
#include "Tokenizer.h"

std::map<TokenTypes, std::string>TokenTypeNames = {
        {NumberLiteral, "NumberLiteral"},
        {Identifier, "Identifier"},
        {Equal, "Equal"},
        {Plus, "Plus"},
        {Minus, "Minus"},
        {Star, "Star"},
        {Slash, "Slash"},
        {A_Slash, "A_Slash"},
        {L_Paren, "L_Paren"},
        {R_Paren, "R_Paren"},
        {L_Bracket, "L_Bracket"},
        {R_Bracket, "R_Bracket"},
        {Semicol, "Semicolon"},
        {Colon, "Colon"},
        {Hashtag, "Hashtag"},
        {L_Angle_Bracket, "L_Angle_Bracket"},
        {R_Angle_Bracket, "R_Angle_Bracket"},
        {Quote, "Quote"},
        {D_Quote, "D_Quote"},
        {Dollar, "Dollar_Sign"},
        {Dot, "Dot"},
        {Comma, "Comma"},
};



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

            result.push_back(Token{TokenTypeNames.at(NumberLiteral), return_num});
            continue;
        }

        if (isalpha(current_char)) {
            std::string return_str(1, current_char);    
            try {
                while (isalnum(code.at(++pos))) {
                    return_str.push_back(code.at(pos));
                }
            } catch (...){}

            result.push_back(Token{TokenTypeNames.at(Identifier), return_str});
            continue;        
        }
        // ignore comments
        if (current_char == '/' && code.at(pos+1) == '*') {
            ++pos;
            while (current_char != '*' && code.at(pos+1) != '/') {
                ++pos;
            }
            pos += 2;
            continue;  
        }

        //ignore single line comments
        if (current_char == '/' && code.at(pos+1) == '/') {
            ++pos;
            while (code.at(pos) != '\n') {
                ++pos;
            }
            continue;  
        }

        //check for symbols
        switch (current_char) {
            case EQUAL: result.push_back(Token{TokenTypeNames.at(Equal), std::string(1, current_char)}); break;
            case SLASH: result.push_back(Token{TokenTypeNames.at(Slash), std::string(1, current_char)}); break;
            case PLUS: result.push_back(Token{TokenTypeNames.at(Plus), std::string(1, current_char)}); break;
            case MINUS: result.push_back(Token{TokenTypeNames.at(Minus), std::string(1, current_char)}); break;
            case STAR: result.push_back(Token{TokenTypeNames.at(Star), std::string(1, current_char)}); break;
            case L_PAR: result.push_back(Token{TokenTypeNames.at(L_Paren), std::string(1, current_char)}); break;
            case R_PAR: result.push_back(Token{TokenTypeNames.at(R_Paren), std::string(1, current_char)}); break;
            case L_BRAQ: result.push_back(Token{TokenTypeNames.at(L_Bracket), std::string(1, current_char)}); break;
            case R_BRAQ: result.push_back(Token{TokenTypeNames.at(R_Bracket), std::string(1, current_char)}); break;
            case SEMI_COLON: result.push_back(Token{TokenTypeNames.at(Semicol), std::string(1, current_char)}); break;
            case COLON: result.push_back(Token{TokenTypeNames.at(Colon), std::string(1, current_char)}); break;
            case HASHTAG: result.push_back(Token{TokenTypeNames.at(Hashtag), std::string(1, current_char)}); break;
            case L_ANGLE_BRA: result.push_back(Token{TokenTypeNames.at(L_Angle_Bracket), std::string(1, current_char)}); break;
            case R_ANGLE_BRA: result.push_back(Token{TokenTypeNames.at(R_Angle_Bracket), std::string(1, current_char)}); break;
            case QUOTE: result.push_back(Token{TokenTypeNames.at(Quote), std::string(1, current_char)}); break;
            case DOUBLE_QUOTE: result.push_back(Token{TokenTypeNames.at(D_Quote), std::string(1, current_char)}); break;
            case DOLLAR: result.push_back(Token{TokenTypeNames.at(Dollar), std::string(1, current_char)}); break;
            case DOT: result.push_back(Token{TokenTypeNames.at(Dot), std::string(1, current_char)}); break;
            case COMMA: result.push_back(Token{TokenTypeNames.at(Dollar), std::string(1, current_char)}); break;
            case SPACE: break;
            case ENDL: break;
            case TAB: break;;
            default:
                std::cerr << "UNDEFINED Token: " << current_char << std::endl;
                result.push_back(Token{"UNDEFINED", std::string(1, current_char)});
                break;
        }
        pos++;
    }

    return result;
}

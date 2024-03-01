#ifndef ARKA_TOKENIZER_H
#define ARKA_TOKENIZER_H

#include <string>
#include <vector>
#include <map>
#include <variant>


enum TokenTypes {
    NumberLiteral,
    Identifier,
    Equal,
    Plus,
    Minus,
    Star,
    Slash,
    L_Paren,
    R_Paren,
    L_Bracket,
    R_Bracket,
    Semicol,
    Colon,
    Hashtag,
    Space,
    Endl,
};

extern std::map<TokenTypes, std::string> TokenTypeNames = {
        {NumberLiteral, "NumberLiteral"},
        {Identifier, "Identifier"},
        {Equal, "Equal"},
        {Plus, "Plus"},
        {Minus, "Minus"},
        {Star, "Star"},
        {Slash, "Slash"},
        {L_Paren, "L_Paren"},
        {R_Paren, "R_Paren"},
        {L_Bracket, "L_Bracket"},
        {R_Bracket, "R_Bracket"},
        {Semicol, "Semicolon"},
        {Colon, "Colon"},
        {Hashtag, "Hashtag"},
        {Space, "Space"},
        {Endl, "Endl"}
};


struct Token {
    std::variant<std::string, TokenTypes> token_type;
    std::string lexem;
};

class Tokenizer {
public:
    std::vector<Token> tokenize(std::string code);
private:

};

#endif //ARKA_TOKENIZER_H

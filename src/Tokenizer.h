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
    A_Slash,
    Tab,
    L_Angle_Bracket,
    R_Angle_Bracket,
    D_Quote,
    Quote,
    Dollar_Sign
};

extern std::map<TokenTypes, std::string> TokenTypeNames;



struct Token {
    std::string token_type;
    std::string lexem;
};

class Tokenizer {
public:
    std::vector<Token> tokenize(std::string code);
private:

};

#endif //ARKA_TOKENIZER_H

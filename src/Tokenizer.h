#ifndef ARKA_TOKENIZER_H
#define ARKA_TOKENIZER_H

#include <string>
#include <vector>

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

struct Token {
    TokenTypes token_type;
    std::string lexem;
};

class Tokenizer {
public:
    std::vector<Token> tokenize(std::string code);
private:

};

#endif //ARKA_TOKENIZER_H

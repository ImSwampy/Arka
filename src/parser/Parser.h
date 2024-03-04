#ifndef ARKA_PARSER_H
#define ARKA_PARSER_H

#include "AST/AST.h"
#include <vector>

class Parser {
public:

    void parse(std::vector<Token> &tokens);

    void identify_tokens(std::vector<Token> tok);


private:

    char separator = ';'; 

    std::vector<Token>::iterator current_token;
    std::vector<Token>::iterator end_token;

    size_t token_list_size;
    Token *tokens = new Token[token_list_size];

    struct Types {
        enum Type {
            VAR,
            FUNCTION,
            IMPORT
        };
        
        
    };
};

#endif //ARKA_PARSER_H
#ifndef ARKA_PARSER_H
#define ARKA_PARSER_H

#include "AST/AST.h"
#include "item/item.h"
#include <vector>

class Parser {
public:

    void parse(std::vector<Token> &tokens); //idk for now

    void identify_tokens(std::vector<Token> tok); // 1 vector<vector<Token>> = a scope, split vector<Token> with ";" 

    void merge_token(std::vector<Token> tok); // detect what the vector is about

    void consume_token(Token tok); // add token to the AST


private:

    Item item;
    Token current_token;
    AST tree;
};

struct Type {

    enum Program {
        name,
        start,
        end
    };

    enum Body {

    };

    enum Expression {
        type,
        value,
        start,
        end
    };

    enum Import {
        name,
        location,
        hash,
    };

    enum Function {
        name,
        return_type,
        parameters,
        value
    };

    enum Classes {
        name,
        value
    };
};



#endif //ARKA_PARSER_H
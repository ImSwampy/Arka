#ifndef ARKA_PARSER_H
#define ARKA_PARSER_H

#include "AST/AST.h"
#include "item/item.h"
#include <vector>
#include <variant>

class Parser {
public:

    void parse(std::vector<Token> &tokens); //idk for now

    void identify_tokens(std::vector<Token> tok); // 1 vector<vector<Token>> = a scope, split vector<Token> with ";" 

    void merge_token(std::vector<Token> tok); // detect what the vector is about (var, func...)

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

    struct Expression {
        std::string type,
        ,
        start,
        end
    };

    struct Function {
        name,
        return_type,
        parameters,
        value
    };

    struct Classes {
        name,
        value
    };

    struct Preprocess {
        std::string type;
        std::string args[];
    };
};



#endif //ARKA_PARSER_H
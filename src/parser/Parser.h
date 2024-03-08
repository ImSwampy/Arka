#ifndef ARKA_PARSER_H
#define ARKA_PARSER_H

#include "AST/AST.h"
#include "item/item.h"
#include "parser_types/Preprocess/Preprocess.h"

#include <vector>
#include <variant>
#include <iostream>
#include <list>
#include <utility>

class Parser {
public:

    void parse(std::vector<Token> &tokens); //idk for now

    std::vector<std::vector<std::vector<Token>>> identify_tokens(std::vector<Token> tok); // 1 vector<vector<Token>> = a scope, split vector<Token> with ";" 

    void merge_token(std::vector<Token> tok); // detect what the vector is about (var, func...)

    void consume_token(Token tok); // add token to the AST


private:

    Item item;
    Token current_token;
    AST tree;
};
/*
struct Type {

    struct Program {
        std::string name;
        uint start;
        uint end;
    };

    struct Body {

    };

    struct Expression {
        std::string type;
        std::string identifier;
        uint start;
        uint end;
    };

    struct Function {
        std::string name;
        std::string return_type;
        int parameters_num;
        std::list<Type::Expression> parameters;
    };

    struct Classes {
        std::string name;
    };

    typedef struct Preprocess {
        std::string type;
        std::string args[];
    };
};
*/


#endif //ARKA_PARSER_H
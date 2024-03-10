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

class Action {
public:
    void add_in_action(Token tok);
    void clear_action();
    std::vector<Token> get_action_content() const;
private:
    std::vector<Token> action;
};

class Scope {
public:
    void add_in_scope(Action action);
    void clear_scope();
    std::vector<Action> get_scope_content() const;
private:
    std::vector<Action> scope;
};

class Program {
public:
    void add_in_program(Scope scope);
    void clear_program();
    std::vector<Scope> get_program_content() const;
private:
    std::vector<Scope> program;
};

class Parser {
public:

    void parse(std::vector<Token> &tokens); //idk for now

    Program identify_tokens(std::vector<Token> tok); // 1 vector<vector<Token>> = a scope, split vector<Token> with ";"

    void merge_token(std::vector<Token> tok); // detect what the vector is about (var, func...)

    void consume_token(Token tok); // add token to the AST


private:
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
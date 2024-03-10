#include "Parser.h"

void Parser::parse(std::vector<Token> &tokens) {

}

Program Parser::identify_tokens(std::vector<Token> tok) {
    Scope scope;
    Program program;
    Action action;

    short int curly_braces_ratio = 0;

    for (size_t pos = 0; pos < tok.size(); pos++) {
        Token curr = tok.at(pos);
        
        if (curr.token_type != TokenTypes::R_Bracket && pos == tok.size()-1) {
            program.add_in_program(scope);
            break;
        }
        switch (curr.token_type) {
            case TokenTypes::Semicol:
                if (!action.get_action_content().empty()) {
                    scope.add_in_scope(action);
                    action.clear_action();
                }
                break;

            case TokenTypes::L_Bracket:
                curly_braces_ratio++;
                break;

            case TokenTypes::R_Bracket:
                curly_braces_ratio--;
                scope.add_in_scope(action);
                action.clear_action();
                break;

            default:
                action.add_in_action(curr);
                break;
            }
        }

    if (curly_braces_ratio != 0) {
        if (curly_braces_ratio > 0) {
            std::cerr << "missing curly braces : '}'" << std::endl;
        } else {
            std::cerr << "missing curly braces : '{'" << std::endl;
        }

        exit(1);
    }

    return program;
}

void Parser::merge_token(std::vector<Token> tok) {

}

void Parser::consume_token(Token tok) {

}

void Scope::add_in_scope(Action action) {
    scope.push_back(action);
}

std::vector<Action> Scope::get_scope_content() const {
    return scope;
}

void Scope::clear_scope() {
    scope.clear();
}

void Program::add_in_program(Scope scope) {
    program.push_back(scope);
}

std::vector<Scope> Program::get_program_content() const {
    return program;
}

void Program::clear_program() {
    program.clear();
}

void Action::add_in_action(Token tok) {
    action.push_back(tok);
}

std::vector<Token> Action::get_action_content() const {
    return action;
}

void Action::clear_action() {
    action.clear();
}

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
                    scope.add_action_in_scope(action);
                    action.clear_action();
                }
                break;

            case TokenTypes::L_Bracket:
                curly_braces_ratio++;
                action.add_in_action(curr);
                break;

            case TokenTypes::R_Bracket:
                curly_braces_ratio--;
                scope.add_action_in_scope(action);
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

void Scope::nest_scope(Scope &scope) {
    //m_Scope.push_back(scope);
}

void Scope::add_action_in_scope(Action &action) {
    //m_Scope.push_back(action);
}

std::vector<Action> Scope::get_scope_content() const {
    return m_Scope;
}

void Scope::clear_scope() {
    m_Scope.clear();
}

void Program::add_in_program(Scope scope) {
    m_Program.push_back(scope);
}

std::vector<Scope> Program::get_program_content() const {
    return m_Program;
}

void Program::clear_program() {
    m_Program.clear();
}

void Action::add_in_action(Token tok) {
    m_Action.push_back(tok);
}

std::vector<Token> Action::get_action_content() const {
    return m_Action;
}

void Action::clear_action() {
    m_Action.clear();
}

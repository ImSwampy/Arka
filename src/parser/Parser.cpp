#include "Parser.h"

void Parser::parse(std::vector<Token> &tokens) {

}

void Parser::identify_tokens(std::vector<Token> tok) {
    TotalType *current_item = new TotalType{};
    Type yes;
    for (Token t : tok) {
        switch (t.token_type) {
            case TokenTypes::Hashtag:
                current_item->preprocess;
                break;
            case TokenTypes::Identifier:
                if (current_item->preprocess.type.empty()) {
                    current_item->preprocess.type = t.lexem;
                } else {
                    current_item->preprocess.args->append(t.lexem);
                }
        }
    }
}

void Parser::merge_token(std::vector<Token> tok) {

}

void Parser::consume_token(Token tok) {

}
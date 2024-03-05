#include "Parser.h"

void Parser::parse(std::vector<Token> &tokens) {
    current_token = tokens.begin();
    end_token = tokens.end();
}

// void Parser::identify_tokens(std::vector<Token> tok) {
//     int token_size = sizeof(tok) / sizeof(Token);
//     for (u_int i = 0; i < token_size; i++) {
//         std::map<std::string, s>
//         TokenTypes current_tok = tok.at(i).token_type;
//         switch (current_tok) {
//             if (current_tok == TokenTypes::Hashtag) {
//                 exit(1);
//             };
//         }
//     }
// }
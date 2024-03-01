#include <iostream>
#include <Tokenizer.h>

int main() {
    Tokenizer tokenizer;
    std::vector<Token> res = tokenizer.tokenize("int main123");
    for (const Token& t : res) {
        std::cout << "[" << t.token_type << "; " << t.lexem << "]" << "";
    }
}
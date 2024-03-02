#include <iostream>
#include <Tokenizer.h>

bool is_useless(std::string s) {
    if (s == "SPACE" || s == "SEMI_COLON" || s == "TAB" || s == "ENDL") {
        return true;
    } else {
        return false;
    }
}


int main() {
    Tokenizer tokenizer;
    std::vector<Token> res = tokenizer.tokenize("var foo<int> = 1;");
    for (const Token& t : res) {
        if (!is_useless(t.token_type)) {
            std::cout << "[" << t.token_type << "; \"" << t.lexem << "\"]" << " ";
        }
    }
}
#include <iostream>
#include <Tokenizer.h>
#include <fstream>

bool is_useless_char(Token t) {

    if (t.lexem == ";" || t.lexem == "=" || t.lexem == "$" || t.token_type == "SEMI_COLON" || t.token_type == "EQUAL" || t.token_type == "Dollar_Sign") {
        return true;
    } else {
        return false;
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::string full_string;
    std::fstream FILE(argv[1], std::ios::in);
    if (!FILE.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    } else {
        std::string buffer;
        while (std::getline(FILE, buffer)) {
            full_string.append(buffer);
        }
    }
    FILE.close();
    Tokenizer tokenizer;
    std::vector<Token> res = tokenizer.tokenize(full_string);
    for (const Token& t : res) {
        if (!is_useless_char(t)){
            std::cout << "[" << t.token_type << "; \"" << t.lexem << "\"]" << " ";
        } else {
            std::cout << "[" << t.token_type << "]" << " ";
        }
        
    }
    return 0;
}
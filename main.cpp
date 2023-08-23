#include "./headers/Lexer.hpp"

int main() {
    Lexer l;

    std::string file = "./readme.cpp";
    l.file_read(file);

    auto tokens = l.analyze();

    std::string tok;
    int tokval;
    for (auto[toke, str]: tokens) {
        switch (toke.index()) {
        case 0:
            tok = "Token::Keyword";
            tokval = int(std::get<Token::Keyword>(toke));
            break;
        
        case 1:
            tok = "Token::Operator";
            tokval = int(std::get<Token::Operator>(toke));
            break;

        case 2:
            tok = "Token::Delimiter";
            tokval = int(std::get<Token::Delimiter>(toke));
            break;

        case 3:
            tok = "Token::Literal";
            tokval = int(std::get<Token::Literal>(toke));
            break;
        
        case 4:
            tok = "Token::Identifier";
            tokval = int(std::get<Token::Identifier>(toke));
            break;
        }

        std::cout << "<" << tok << "::" << std::to_string(tokval) << ", " << (str).value_or("") << ">\n";
    }

    return 0;
}
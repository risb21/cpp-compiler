#include "./headers/Lexer.hpp"

int main() {
    Lexer l;
    
    std::string file = "readme.cpp";
    l.file_read(file);

    
    return 0;
}
#pragma once

#include <iostream>
#include <ios>
#include <fstream>
#include <sstream>
#include <vector>

enum class Token {
    INCLUDE,
    LIBRARY,
    INT_LITERAL,
    OPERATOR,
    


};

class Lexer {
public:

    Lexer() {}
    ~Lexer() {}

    void file_read(std::string path);

private:
    std::string file_content;

};

void Lexer::file_read(std::string path) {
    std::stringstream filec;
    std::ifstream file;
    std::string line;

    file.open(path, std::ios::out);

    while (getline(file, line)) {
        filec << line << std::endl;
    }

    file.close();

    file_content = filec.str();
}


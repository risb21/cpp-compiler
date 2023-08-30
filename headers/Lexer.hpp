#pragma once

#include "Token_types.hpp"

#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include <iostream>
#include <ios>
#include <fstream>
#include <sstream>
#include <vector>
#include <optional>
#include <variant>

class Lexer {
public:

    Lexer() {}
    ~Lexer() {}

    void file_read(std::string& path);
    std::vector<std::pair<std::variant<
        Token::Keyword, Token::Operator, Token::Delimiter, Token::Literal, Token::Identifier
    >, std::optional<std::string>>> analyze();

private:
    std::string file_content;
    
    std::vector<std::pair<std::variant<
        Token::Keyword, Token::Operator, Token::Delimiter, Token::Literal, Token::Identifier
    >, std::optional<std::string>>> tokens;

    const std::string op3 = "<<=>>=",
        op2 = "==++--!=%=^=&=*=-=+=/=|=>><<<=>=&&||",
        op1 = "!=-+*&^%/><|";

    using TK = Token::Keyword;
    using TD = Token::Delimiter;
    using TO = Token::Operator;

    const std::unordered_map<char, Token::Delimiter> delimiter_map = {
        {'{', TD::L_CURLY}, {'}', TD::R_CURLY}, {'(', TD::L_PARENTHESIS},
        {')', TD::R_PARENTHESIS}, {'[', TD::L_SQUARE}, {']', TD::L_CURLY},
        {'<', TD::L_ANGLED}, {'>', TD::R_ANGLED}, {';', TD::SEMICOLON}
    };

    const std::unordered_map<std::string, Token::Operator> operator_map = {
        {"<<=", TO::LSHIFT_ASSIGN}, {">>=", TO::RSHIFT_ASSIGN}, {"==", TO::EQUATE},
        {"++", TO::INCREMENT}, {"--", TO::DECREMENT}, {"!=", TO::NOT_EQUAL},
        {"%=", TO::MOD_ASSIGN}, {"^=", TO::XOR_ASSIGN}, {"&=", TO::AND_ASSIGN}, 
        {"*=", TO::MULT_ASSIGN}, {"-=", TO::SUB_ASSIGN}, {"+=", TO::ADD_ASSIGN}, 
        {"/=", TO::DIV_ASSIGN}, {"|=", TO::OR_ASSIGN}, {"<<", TO::LSHIFT}, 
        {">>", TO::RSHIFT}, {"<=", TO::LTE}, {">=", TO::GTE}, {"&&", TO::LOGICAL_AND},
        {"||", TO::LOGICAL_OR}, {"!", TO::LOGICAL_NOT}, {"=", TO::ASSIGN}, 
        {"-", TO::SUB}, {"+", TO::ADD}, {"*", TO::MULT}, {"&", TO::AND}, 
        {"^", TO::XOR}, {"%", TO::MOD}, {"/", TO::DIV}, {">", TO::GT}, 
        {"<", TO::LT}, {"|", TO::OR}
    };

    const std::unordered_map<std::string, Token::Keyword> keyword_map = {
        {"or", TK::OR}, {"do", TK::DO}, {"if", TK::IF},
        {"int", TK::INT}, {"not", TK::NOT}, {"new", TK::NEW},
        {"for", TK::FOR}, {"asm", TK::ASM}, {"xor", TK::XOR},
        {"and", TK::AND}, {"try", TK::TRY}, {"enum", TK::ENUM},
        {"case", TK::CASE}, {"bool", TK::BOOL}, {"auto", TK::AUTO},
        {"void", TK::VOID}, {"char", TK::CHAR}, {"goto", TK::GOTO},
        {"this", TK::THIS}, {"else", TK::ELSE}, {"long", TK::LONG},
        {"or_eq", TK::OR_EQ}, {"class", TK::CLASS}, {"compl", TK::COMPL},
        {"throw", TK::THROW}, {"const", TK::CONST}, {"short", TK::SHORT},
        {"catch", TK::CATCH}, {"break", TK::BREAK}, {"bitor", TK::BITOR},
        {"union", TK::UNION}, {"using", TK::USING}, {"float", TK::FLOAT},
        {"while", TK::WHILE}, {"delete", TK::DELETE}, {"double", TK::DOUBLE},
        {"bitand", TK::BITAND}, {"and_eq", TK::AND_EQ}, {"export", TK::EXPORT},
        {"extern", TK::EXTERN}, {"friend", TK::FRIEND}, {"xor_eq", TK::XOR_EQ},
        {"inline", TK::INLINE}, {"struct", TK::STRUCT}, {"static", TK::STATIC},
        {"sizeof", TK::SIZEOF}, {"signed", TK::SIGNED}, {"not_eq", TK::NOT_EQ},
        {"return", TK::RETURN}, {"typeid", TK::TYPEID}, {"public", TK::PUBLIC},
        {"switch", TK::SWITCH}, {"typedef", TK::TYPEDEF}, {"nullptr", TK::NULLPTR},
        {"private", TK::PRIVATE}, {"default", TK::DEFAULT}, {"mutable", TK::MUTABLE},
        {"concept", TK::CONCEPT}, {"char8_t", TK::CHAR8_T}, {"virtual", TK::VIRTUAL},
        {"wchar_t", TK::WCHAR_T}, {"alignof", TK::ALIGNOF}, {"alignas", TK::ALIGNAS},
        {"noexcept", TK::NOEXCEPT}, {"decltype", TK::DECLTYPE}, {"reflexpr", TK::REFLEXPR},
        {"register", TK::REGISTER}, {"requires", TK::REQUIRES}, {"co_yield", TK::CO_YIELD},
        {"explicit", TK::EXPLICIT}, {"co_await", TK::CO_AWAIT}, {"volatile", TK::VOLATILE},
        {"unsigned", TK::UNSIGNED}, {"typename", TK::TYPENAME}, {"operator", TK::OPERATOR},
        {"template", TK::TEMPLATE}, {"char16_t", TK::CHAR16_T}, {"char32_t", TK::CHAR32_T},
        {"continue", TK::CONTINUE}, {"co_return", TK::CO_RETURN},
        {"protected", TK::PROTECTED}, {"constinit", TK::CONSTINIT},
        {"constexpr", TK::CONSTEXPR}, {"consteval", TK::CONSTEVAL},
        {"namespace", TK::NAMESPACE}, {"const_cast", TK::CONST_CAST},
        {"static_cast", TK::STATIC_CAST}, {"thread_local", TK::THREAD_LOCAL},
        {"synchronized", TK::SYNCHRONIZED}, {"dynamic_cast", TK::DYNAMIC_CAST},
        {"static_assert", TK::STATIC_ASSERT}, {"atomic_commit", TK::ATOMIC_COMMIT},
        {"atomic_cancel", TK::ATOMIC_CANCEL}, {"atomic_noexcept", TK::ATOMIC_NOEXCEPT},
        {"reinterpret_cast", TK::REINTERPRET_CAST}
    };
    const std::vector<std::string> keywords = {
        "if", "or", "do", "try", "and", "xor", "asm", "for", "int",
        "new", "not", "long", "else", "enum", "this", "goto", "char",
        "void", "auto", "bool", "case", "or_eq", "while", "float",
        "using", "union", "bitor", "break", "catch", "short", "const",
        "throw", "compl", "class", "public", "typeid", "return",
        "not_eq", "signed", "sizeof", "static", "struct", "switch",
        "inline", "xor_eq", "friend", "extern", "export", "and_eq",
        "bitand", "double", "delete", "alignas", "alignof", "wchar_t",
        "virtual", "char8_t", "typedef", "concept", "mutable", "default",
        "private", "nullptr", "char32_t", "char16_t", "template",
        "operator", "typename", "unsigned", "noexcept", "volatile",
        "continue", "co_await", "explicit", "co_yield", "requires",
        "register", "reflexpr", "decltype", "namespace", "consteval",
        "constexpr", "constinit", "co_return", "protected", "const_cast",
        "static_cast", "thread_local", "synchronized", "dynamic_cast",
        "static_assert", "atomic_commit", "atomic_cancel", "atomic_noexcept",
        "reinterpret_cast"
    };

    const std::unordered_set<std::string> type_keywords = {
        "int", "char", "long", "void", "bool", "float", "short", "double",
        "wchar_t", "char8_t", "char16_t", "char32_t"
    };
    int isOperator(int idx);
    // bool isKeyword(std::string& buf);
};

void Lexer::file_read(std::string& path) {
    std::stringstream filec;
    std::ifstream file;
    std::string line;

    file.open(path, std::ios::out);

    while (getline(file, line))
        filec << line << std::endl;
    file.close();

    file_content = filec.str();

    std::cout << file_content;
}


std::vector<std::pair<std::variant<
    // Token types
    Token::Keyword, Token::Operator, Token::Delimiter, Token::Literal, Token::Identifier
>, std::optional<std::string>>> Lexer::analyze() {
    
    std::string buffer;

    for (int i = 0; i < file_content.length(); i++) {

        // remove comments 
        if (i < file_content.length() - 1 && file_content.substr(i, 2) == "//") {
            for (int idx = i+2; idx < file_content.length(); idx++) {
                if (file_content[idx] == '\n') {
                    i = idx + 1;
                    break;
                }
            }
        }

        if (i < file_content.length() - 1 && file_content.substr(i, 2) == "/*") {
            for (int idx = i+2; idx < file_content.length(); idx++) {
                if (idx < file_content.length() - 1 && file_content.substr(idx, 2) == "*/") {
                    i = idx + 2;
                    break;
                }
            }
        }

        // Region is now free from comments
        
        // Delimiters
        if (delimiter_map.count(file_content[i]) != 0) {
            std::string delim;
            delim += file_content[i];
            tokens.push_back({delimiter_map.at(file_content[i]), delim});
            continue;
        }
        
        // identifiers or keywords
        if (isalpha(file_content[i]) || file_content[i] == '_') {
            buffer += file_content[i];
            for (int idx = i+1; idx < file_content.length(); idx++) {
                if (isalnum(file_content[idx]) || file_content[idx] == '_')
                    buffer += file_content[idx];
                else {
                    // check for keyword (followed by whitespace or delimiter) else token
                    if (keyword_map.count(buffer) != 0 && (
                            idx == file_content.length() - 1 || file_content[idx+1] != ' ' ||
                            file_content[idx+1] != '\n' || delimiter_map.count(file_content[idx+1]) != 0
                        )) {
                        tokens.push_back({keyword_map.at(buffer), buffer});
                        // std::nullopt});
                    }
                    // Definitely an identifier
                    else {
                        tokens.push_back({Token::Identifier::BASE, buffer});
                    }

                    i = idx - 1;
                    buffer.clear();
                    break;
                }
            }
        }

        // Operators (correctly identify template braces)
        int opsize;
        if (opsize = isOperator(i)) {
            i += opsize - 1;
        }

    }

    return tokens;
}

int Lexer::isOperator(int idx) {
    std::string sub;

    for (int oplen = 3; oplen > 0; oplen--) {
        if (file_content.length() - idx >= oplen) {
            sub = file_content.substr(idx, oplen);
            if (operator_map.count(sub) != 0) {
                tokens.push_back({operator_map.at(sub), sub});
                return oplen;
            }
        }
    }
    
    return false;
}

// bool Lexer::isKeyword(std::string& buf) {




//     return false;
// }
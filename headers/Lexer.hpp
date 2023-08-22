#pragma once

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
// #include <type_traits>
// #include <utility>
// #include <iomanip>

bool sortfn(std::string& a, std::string& b) {
    return a.length() < b.length();
}



namespace Token {
    enum class Identifier {
        BASE,
    };

    enum class Operator {
        GTE, LTE, GT, LT, NOT_EQUAL, EQUATE, ASSIGN,
        ADD, SUB, MULT, DIV, NOT, MOD, XOR, AND, OR,
        LOGICAL_NOT, LOGICAL_AND, LOGICAL_OR, LSHIFT,
        RSHIFT, ADD_ASSIGN, SUB_ASSIGN, MULT_ASSIGN,
        DIV_ASSIGN, AND_ASSIGN, OR_ASSIGN, XOR_ASSIGN,
        MOD_ASSIGN, LSHIFT_ASSIGN, RSHIFT_ASSIGN, UNARY_POS,
        UNARY_NEG, TERNARY_IF, TERNARY_ELSE, INCREMENT, DECREMENT
    };

    enum class Keyword {
        OR, DO, IF, INT, NOT, NEW, FOR, ASM, XOR, AND, TRY,
        ENUM, CASE, BOOL, AUTO, VOID, CHAR, GOTO, THIS, ELSE, 
        LONG, OR_EQ, CLASS, COMPL, THROW, CONST, SHORT, CATCH,
        BREAK, BITOR, UNION, USING, FLOAT, WHILE, DELETE, DOUBLE,
        BITAND, AND_EQ, EXPORT, EXTERN, FRIEND, XOR_EQ, INLINE,
        STRUCT, STATIC, SIZEOF, SIGNED, NOT_EQ, RETURN, TYPEID,
        PUBLIC, SWITCH, TYPEDEF, NULLPTR, PRIVATE, DEFAULT, MUTABLE,
        CONCEPT, CHAR8_T, VIRTUAL, WCHAR_T, ALIGNOF, ALIGNAS, NOEXCEPT,
        DECLTYPE, REFLEXPR, REGISTER, REQUIRES, CO_YIELD, EXPLICIT,
        CO_AWAIT, VOLATILE, UNSIGNED, TYPENAME, OPERATOR, TEMPLATE,
        CHAR16_T, CHAR32_T, CONTINUE, CO_RETURN, PROTECTED, CONSTINIT,
        CONSTEXPR, CONSTEVAL, NAMESPACE, CONST_CAST, STATIC_CAST,
        THREAD_LOCAL, SYNCHRONIZED, DYNAMIC_CAST, STATIC_ASSERT,ATOMIC_COMMIT,
        ATOMIC_CANCEL, ATOMIC_NOEXCEPT, REINTERPRET_CAST, 
    };

    enum class Delimiter {
        L_CURLY, R_CURLY, L_SQUARE, R_SQUARE, L_PARENTHESIS,
        R_PARENTHESIS, L_ANGLED, R_ANGLED, SEMICOLON,
    };

    enum class Literal {
        INT, FLOAT, STRING, CHAR, HEX, OCT, BIN, BOOL
    };
}

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
        op1 = "!=-*&^%/><|";

    using TK = Token::Keyword;
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
    bool isOperator(std::string& buf);
    bool isKeyword(std::string& buf);


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
    Token::Keyword, Token::Operator, Token::Delimiter, Token::Literal, Token::Identifier
>, std::optional<std::string>>> Lexer::analyze() {
    
    std::string buffer;

    for (int i = 0; i < file_content.length(); i++) {

        // if (true) {

        // }
        
        // identifiers or keywords
        if (isalpha(file_content[i]) || file_content[i] == '_') {
            buffer += file_content[i];
            for (int idx = i+1; idx < file_content.length(); idx++) {

                if (isalnum(file_content[idx]) || file_content[idx] == '_')
                    buffer += file_content[idx];
                else {
                    // check for keyword, else token
                    if (keyword_map.count(buffer) != 0 && 
                        (idx == file_content.length() - 1 || file_content[idx+1] != ' ' || file_content[idx+1] != '\n')) {
                        tokens.push_back({keyword_map.at(buffer), buffer});
                        // std::nullopt});
                    } 
                    // check for type casts
                    else if (type_keywords.count(buffer) != 0) {
                        tokens.push_back({keyword_map.at(buffer),  buffer});
                        // std::nullopt});
                    }
                    // Definitely an identifier
                    else {
                        tokens.push_back({Token::Identifier::BASE, buffer});
                    }

                    
                    std::string tok;
                    int tokval;
                    switch (tokens.back().first.index()) {
                        case 0:
                            tok = "Token::Keyword";
                            tokval = int(std::get<Token::Keyword>(tokens.back().first));
                            break;
                        
                        case 1:
                            tok = "Token::Operator";
                            tokval = int(std::get<Token::Operator>(tokens.back().first));
                            break;

                        case 2:
                            tok = "Token::Delimiter";
                            tokval = int(std::get<Token::Delimiter>(tokens.back().first));
                            break;

                        case 3:
                            tok = "Token::Literal";
                            tokval = int(std::get<Token::Literal>(tokens.back().first));
                            break;
                        
                        case 4:
                            tok = "Token::Identifier";
                            tokval = int(std::get<Token::Identifier>(tokens.back().first));
                            break;
                    }

                    std::cout << "<" << tok << "::" << std::to_string(tokval) << ", " << (tokens.back().second).value_or("") << ">\n";
                        
                    i = idx - 1;
                    buffer.clear();
                    break;
                }
            }
        }

    }

    return tokens;
}

bool Lexer::isOperator(std::string& buf) {
    
    // Check for 3 length operators
    for (int i = 0; i < buf.length(); i += 3) {

    }


    return false;
    
}

bool Lexer::isKeyword(std::string& buf) {




    return false;
}
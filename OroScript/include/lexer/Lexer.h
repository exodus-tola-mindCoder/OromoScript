#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {
    EOF_TOKEN,
    IDENTIFIER,
    NUMBER,
    STRING,
    PLUS, MINUS, STAR, SLASH,
    TOK_IF,  // yoo
    TOK_PRINT,  // baasi
    // Add more: TOK_WHILE (yeroo), TOK_TRUE (dhugaa), etc.
};

struct Token {
    TokenType type;
    std::string value;
    int line;
};

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> lex();

private:
    std::string source;
    size_t pos = 0;
    int line = 1;

    char currentChar();
    void advance();
    void skipWhitespace();
    Token identifier();
    Token number();
    Token string();
};

#endif
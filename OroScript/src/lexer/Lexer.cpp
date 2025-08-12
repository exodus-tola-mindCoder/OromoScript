#include "lexer/Lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& src) : source(src) {}

char Lexer::currentChar() {
    return pos < source.size() ? source[pos] : '\0';
}

void Lexer::advance() {
    if (currentChar() == '\n') line++;
    pos++;
}

void Lexer::skipWhitespace() {
    while (std::isspace(currentChar())) advance();
}

Token Lexer::identifier() {
    std::string value;
    while (std::isalnum(currentChar()) || currentChar() == '_') {
        value += currentChar();
        advance();
    }
    TokenType type = TokenType::IDENTIFIER;
    if (value == "yoo") type = TokenType::TOK_IF;
    else if (value == "baasi") type = TokenType::TOK_PRINT;
    // Add more keywords here
    return {type, value, line};
}

Token Lexer::number() {
    std::string value;
    while (std::isdigit(currentChar())) {
        value += currentChar();
        advance();
    }
    return {TokenType::NUMBER, value, line};
}

Token Lexer::string() {
    advance();  // Skip opening quote
    std::string value;
    while (currentChar() != '"' && currentChar() != '\0') {
        value += currentChar();
        advance();
    }
    if (currentChar() == '\0') throw std::runtime_error("Unterminated string");
    advance();  // Skip closing quote
    return {TokenType::STRING, value, line};
}

std::vector<Token> Lexer::lex() {
    std::vector<Token> tokens;
    while (pos < source.size()) {
        skipWhitespace();
        char c = currentChar();
        if (c == '\0') break;
        if (std::isalpha(c) || c == '_') {
            tokens.push_back(identifier());
        } else if (std::isdigit(c)) {
            tokens.push_back(number());
        } else if (c == '"') {
            tokens.push_back(string());
        } else if (c == '+') { tokens.push_back({TokenType::PLUS, "+", line}); advance(); }
        else if (c == '-') { tokens.push_back({TokenType::MINUS, "-", line}); advance(); }
        else if (c == '*') { tokens.push_back({TokenType::STAR, "*", line}); advance(); }
        else if (c == '/') { tokens.push_back({TokenType::SLASH, "/", line}); advance(); }
        else {
            throw std::runtime_error("Unexpected character: " + std::string(1, c));
        }
    }
    tokens.push_back({TokenType::EOF_TOKEN, "", line});
    return tokens;
}
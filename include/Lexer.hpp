#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include "Token.hpp"

// The Lexer is responsible for scanning the raw source code text
// and converting it into a sequence of Tokens.
class Lexer {
public:
    Lexer(const std::string& source);

    // Scans all tokens from the source and returns them.
    std::vector<Token> scanTokens();

private:
    const std::string& source;
    static const std::unordered_map<std::string, TokenType> keywords;
    std::vector<Token> tokens;

    int start = 0;
    int current = 0;
    int line = 1;

    // Helper functions
    bool isAtEnd() const;
    void scanToken();
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, const std::string& literal);
    bool match(char expected);
    char peek() const;
    char peekNext() const;

    // Token type scanning functions
    void string();
    void number();
    void identifier();
};
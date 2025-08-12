#pragma once

#include <string>
#include <ostream>

// Defines the different types of tokens our language recognizes.
enum class TokenType {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords.
    FI, GITA, TAANAN, SOBA, HOJII, YEROOF, YOO, DUWWA, YKN,
    BAASI, DEEBISI, GUDDOO, KANA, DHUGAA, MAQAA, YEROO,

    ERROR,
    END_OF_FILE
};

// Represents a single token scanned from the source code.
class Token {
public:
    const TokenType type;
    const std::string lexeme;
    const int line;

    Token(TokenType type, std::string lexeme, int line);

    std::string toString() const;
};
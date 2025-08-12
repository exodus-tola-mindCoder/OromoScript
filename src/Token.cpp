#include "Token.hpp"
#include <map>

Token::Token(TokenType type, std::string lexeme, int line)
    : type(type), lexeme(std::move(lexeme)), line(line) {}

std::string Token::toString() const {
    // A map to convert TokenType enums to their string representation.
    static const std::map<TokenType, std::string> tokenStrings = {
        {TokenType::LEFT_PAREN, "LEFT_PAREN"}, {TokenType::RIGHT_PAREN, "RIGHT_PAREN"},
        {TokenType::LEFT_BRACE, "LEFT_BRACE"}, {TokenType::RIGHT_BRACE, "RIGHT_BRACE"},
        {TokenType::COMMA, "COMMA"}, {TokenType::DOT, "DOT"},
        {TokenType::MINUS, "MINUS"}, {TokenType::PLUS, "PLUS"},
        {TokenType::SEMICOLON, "SEMICOLON"}, {TokenType::SLASH, "SLASH"},
        {TokenType::STAR, "STAR"}, {TokenType::BANG, "BANG"},
        {TokenType::BANG_EQUAL, "BANG_EQUAL"}, {TokenType::EQUAL, "EQUAL"},
        {TokenType::EQUAL_EQUAL, "EQUAL_EQUAL"}, {TokenType::GREATER, "GREATER"},
        {TokenType::GREATER_EQUAL, "GREATER_EQUAL"}, {TokenType::LESS, "LESS"},
        {TokenType::LESS_EQUAL, "LESS_EQUAL"}, {TokenType::IDENTIFIER, "IDENTIFIER"},
        {TokenType::STRING, "STRING"}, {TokenType::NUMBER, "NUMBER"},
        {TokenType::FI, "FI (AND)"}, {TokenType::GITA, "GITA (CLASS)"},
        {TokenType::TAANAN, "TAANAN (ELSE)"}, {TokenType::SOBA, "SOBA (FALSE)"},
        {TokenType::HOJII, "HOJII (FUN)"}, {TokenType::YEROOF, "YEROOF (FOR)"},
        {TokenType::YOO, "YOO (IF)"}, {TokenType::DUWWA, "DUWWA (NIL)"},
        {TokenType::YKN, "YKN (OR)"}, {TokenType::BAASI, "BAASI (PRINT)"},
        {TokenType::DEEBISI, "DEEBISI (RETURN)"}, {TokenType::GUDDOO, "GUDDOO (SUPER)"},
        {TokenType::KANA, "KANA (THIS)"}, {TokenType::DHUGAA, "DHUGAA (TRUE)"},
        {TokenType::MAQAA, "MAQAA (VAR)"}, {TokenType::YEROO, "YEROO (WHILE)"},
        {TokenType::ERROR, "ERROR"}, {TokenType::END_OF_FILE, "EOF"}
    };

    auto it = tokenStrings.find(type);
    std::string typeStr = (it != tokenStrings.end()) ? it->second : "UNKNOWN";

    return typeStr + " " + lexeme;
}
#include "Lexer.hpp"
#include <iostream>
#include <utility>
#include <cctype>

// Initialize the static map of keywords
const std::unordered_map<std::string, TokenType> Lexer::keywords = {
    {"fi",      TokenType::FI},
    {"gita",    TokenType::GITA},
    {"taanan",  TokenType::TAANAN},
    {"soba",    TokenType::SOBA},
    {"hojii",   TokenType::HOJII},
    {"yeroof",  TokenType::YEROOF},
    {"yoo",     TokenType::YOO},
    {"duwwa",   TokenType::DUWWA},
    {"ykn",     TokenType::YKN},
    {"baasi",   TokenType::BAASI},
    {"deebisi", TokenType::DEEBISI},
    {"guddoo",  TokenType::GUDDOO},
    {"kana",    TokenType::KANA},
    {"dhugaa",  TokenType::DHUGAA},
    {"maqaa",   TokenType::MAQAA},
    {"yeroo",   TokenType::YEROO},
};

Lexer::Lexer(const std::string& source) : source(source) {}

std::vector<Token> Lexer::scanTokens() {
    while (!isAtEnd()) {
        // We are at the beginning of the next lexeme.
        start = current;
        scanToken();
    }

    tokens.emplace_back(TokenType::END_OF_FILE, "", line);
    return std::move(tokens);
}

bool Lexer::isAtEnd() const {
    return current >= source.length();
}

void Lexer::scanToken() {
    char c = advance();
    switch (c) {
        case '(': addToken(TokenType::LEFT_PAREN); break;
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '{': addToken(TokenType::LEFT_BRACE); break;
        case '}': addToken(TokenType::RIGHT_BRACE); break;
        case ',': addToken(TokenType::COMMA); break;
        case '.': addToken(TokenType::DOT); break;
        case '-': addToken(TokenType::MINUS); break;
        case '+': addToken(TokenType::PLUS); break;
        case ';': addToken(TokenType::SEMICOLON); break;
        case '*': addToken(TokenType::STAR); break;
        case '!': addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG); break;
        case '=': addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL); break;
        case '<': addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS); break;
        case '>': addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER); break;

        case '/':
            if (match('/')) {
                // A comment goes until the end of the line.
                while (peek() != '\n' && !isAtEnd()) advance();
            } else {
                addToken(TokenType::SLASH);
            }
            break;

        // Ignore whitespace.
        case ' ':
        case '\r':
        case '\t':
            break;

        case '\n':
            line++;
            break;

        case '"': string(); break;

        default:
            if (isdigit(c)) {
                number();
            } else if (isalpha(c) || c == '_') {
                identifier();
            } else {
                std::cerr << "[Garee " << line << "] Dogoggora: Mallattoo hin eegamne '" << c << "'" << std::endl;
            }
            break;
    }
}

void Lexer::identifier() {
    while (isalnum(peek()) || peek() == '_') advance();

    std::string text = source.substr(start, current - start);
    TokenType type;
    auto it = keywords.find(text);
    if (it == keywords.end()) {
        type = TokenType::IDENTIFIER;
    } else {
        type = it->second;
    }
    addToken(type);
}

void Lexer::number() {
    while (isdigit(peek())) advance();

    // Look for a fractional part.
    if (peek() == '.' && isdigit(peekNext())) {
        // Consume the "."
        advance();

        while (isdigit(peek())) advance();
    }

    addToken(TokenType::NUMBER, source.substr(start, current - start));
}

void Lexer::string() {
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line++;
        advance();
    }

    if (isAtEnd()) {
        std::cerr << "[Garee " << line << "] Dogoggora: Jechi xumura hin qabu." << std::endl;
        return;
    }

    // The closing ".
    advance();

    // Trim the surrounding quotes.
    std::string value = source.substr(start + 1, current - start - 2);
    addToken(TokenType::STRING, value);
}

bool Lexer::match(char expected) {
    if (isAtEnd()) return false;
    if (source[current] != expected) return false;

    current++;
    return true;
}

char Lexer::peek() const {
    if (isAtEnd()) return '\0';
    return source[current];
}

char Lexer::peekNext() const {
    if (current + 1 >= source.length()) return '\0';
    return source[current + 1];
}

char Lexer::advance() {
    return source[current++];
}

void Lexer::addToken(TokenType type) {
    std::string text = source.substr(start, current - start);
    tokens.emplace_back(type, std::move(text), line);
}

void Lexer::addToken(TokenType type, const std::string& literal) {
    tokens.emplace_back(type, literal, line);
}
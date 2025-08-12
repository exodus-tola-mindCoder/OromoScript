#include "parser/Parser.h"
#include "utils/Errors.h"

Parser::Parser(const std::vector<Token>& t) : tokens(t) {}

Token Parser::current() {
    return pos < tokens.size() ? tokens[pos] : Token{TokenType::EOF_TOKEN, "", -1};
}

void Parser::advance() { pos++; }

std::unique_ptr<Node> Parser::parseStmt() {
    if (current().type == TokenType::TOK_PRINT) {
        advance();
        // Parse expression (stub: assume a string literal for now)
        if (current().type != TokenType::STRING) throw SyntaxError("Expected string after baasi");
        auto expr = std::make_unique<PrintNode>(nullptr);  // Stub
        advance();
        return expr;
    }
    throw SyntaxError("Unexpected token");
}

std::unique_ptr<Node> Parser::parse() {
    return parseStmt();  // Expand to parse program (multiple stmts)
}
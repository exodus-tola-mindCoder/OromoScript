#ifndef PARSER_H
#define PARSER_H

#include "lexer/Lexer.h"
#include "ast/Node.h"
#include <vector>
#include <memory>

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::unique_ptr<Node> parse();

private:
    std::vector<Token> tokens;
    size_t pos = 0;

    Token current();
    void advance();
    std::unique_ptr<Node> parseStmt();
    // Add parseExpr(), etc.
};

#endif
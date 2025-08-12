#ifndef OROSCRIPT_PARSER_H
#define OROSCRIPT_PARSER_H

#include <vector>
#include <memory>
#include "../lexer/Lexer.h"
#include "../ast/Node.h"

namespace OroScript {

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::unique_ptr<AST::Program> parse();
    
private:
    std::vector<Token> tokens;
    int current;
    
    bool isAtEnd();
    Token& peek();
    Token& previous();
    bool check(TokenType type);
    bool match(TokenType type);
    Token advance();
    Token consume(TokenType type, const std::string& message);
    
    std::unique_ptr<AST::Program> program();
    std::unique_ptr<AST::Statement> statement();
    std::unique_ptr<AST::Statement> declaration();
    std::unique_ptr<AST::Statement> variableDeclaration();
    std::unique_ptr<AST::Statement> functionDeclaration();
    std::unique_ptr<AST::Statement> ifStatement();
    std::unique_ptr<AST::Statement> whileStatement();
    std::unique_ptr<AST::Statement> expressionStatement();
    std::unique_ptr<AST::Expression> expression();
    std::unique_ptr<AST::Expression> equality();
    std::unique_ptr<AST::Expression> comparison();
    std::unique_ptr<AST::Expression> term();
    std::unique_ptr<AST::Expression> factor();
    std::unique_ptr<AST::Expression> unary();
    std::unique_ptr<AST::Expression> primary();
};

} // namespace OroScript

#endif // OROSCRIPT_PARSER_H

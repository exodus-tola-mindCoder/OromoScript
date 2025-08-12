#ifndef OROSCRIPT_SEMANTIC_ANALYZER_H
#define OROSCRIPT_SEMANTIC_ANALYZER_H

#include "../ast/Visitor.h"
#include "../utils/SymbolTable.h"
#include <vector>
#include <string>

namespace OroScript {

class SemanticAnalyzer : public AST::Visitor {
public:
    void analyze(AST::Program& program);
    
    // Visitor interface
    void visit(AST::NumberLiteral& node) override;
    void visit(AST::StringLiteral& node) override;
    void visit(AST::BooleanLiteral& node) override;
    void visit(AST::Identifier& node) override;
    void visit(AST::BinaryExpression& node) override;
    void visit(AST::UnaryExpression& node) override;
    void visit(AST::FunctionCall& node) override;
    void visit(AST::ExpressionStatement& node) override;
    void visit(AST::VariableDeclaration& node) override;
    void visit(AST::FunctionDeclaration& node) override;
    void visit(AST::IfStatement& node) override;
    void visit(AST::WhileStatement& node) override;
    void visit(AST::Program& node) override;

private:
    SymbolTable symbolTable;
    std::vector<std::string> errors;
    
    void reportError(const std::string& message, int line = 0);
};

} // namespace OroScript

#endif // OROSCRIPT_SEMANTIC_ANALYZER_H

#ifndef OROSCRIPT_EVALUATOR_H
#define OROSCRIPT_EVALUATOR_H

#include "../ast/Visitor.h"
#include "../utils/SymbolTable.h"
#include <any>
#include <vector>
#include <memory>

namespace OroScript {

class Evaluator : public AST::Visitor {
public:
    std::any evaluate(AST::Program& program);
    
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
    std::any lastValue;
};

} // namespace OroScript

#endif // OROSCRIPT_EVALUATOR_H

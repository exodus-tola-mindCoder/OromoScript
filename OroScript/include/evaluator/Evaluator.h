#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "ast/Node.h"
#include "ast/Visitor.h"

class Evaluator : public Visitor {
public:
    void evaluate(Node* ast);
    void visit(PrintNode& node) override;
    // Add more visit methods
};

#endif
#include "evaluator/Evaluator.h"
#include <iostream>

void Evaluator::evaluate(Node* ast) {
    ast->accept(*this);
}

void Evaluator::visit(PrintNode& node) {
    std::cout << "Hello from evaluator! (Stub output)" << std::endl;
}
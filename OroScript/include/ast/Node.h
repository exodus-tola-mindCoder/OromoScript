#ifndef NODE_H
#define NODE_H

#include <memory>
#include "Visitor.h"

class Node {
public:
    virtual ~Node() = default;
    virtual void accept(Visitor& visitor) = 0;
};

// Example derived node: ExprNode, StmtNode, etc. Add as needed
class PrintNode : public Node {
public:
    std::unique_ptr<Node> expr;
    PrintNode(std::unique_ptr<Node> e) : expr(std::move(e)) {}
    void accept(Visitor& visitor) override { visitor.visit(*this); }
};

#endif
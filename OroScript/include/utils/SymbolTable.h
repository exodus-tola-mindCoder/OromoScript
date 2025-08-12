#ifndef OROSCRIPT_UTILS_SYMBOLTABLE_H
#define OROSCRIPT_UTILS_SYMBOLTABLE_H

#include <unordered_map>
#include <string>
#include <any>
#include <memory>

namespace OroScript {

class Symbol {
public:
    enum Type {
        VARIABLE,
        FUNCTION
    };
    
    Symbol(const std::string& name, Type t, const std::any& value = nullptr)
        : name(name), type(t), value(value) {}
    
    std::string name;
    Type type;
    std::any value;
};

class SymbolTable {
public:
    SymbolTable();
    explicit SymbolTable(std::shared_ptr<SymbolTable> parent);
    
    void define(const std::string& name, const Symbol& symbol);
    Symbol* resolve(const std::string& name);
    bool exists(const std::string& name) const;
    
    std::shared_ptr<SymbolTable> getParent() const;
    
private:
    std::unordered_map<std::string, Symbol> symbols;
    std::shared_ptr<SymbolTable> parent;
};

} // namespace OroScript

#endif // OROSCRIPT_UTILS_SYMBOLTABLE_H

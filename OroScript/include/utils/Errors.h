#ifndef OROSCRIPT_UTILS_ERRORS_H
#define OROSCRIPT_UTILS_ERRORS_H

#include <string>
#include <vector>

namespace OroScript {

class Error {
public:
    enum Type {
        LEXICAL,
        SYNTAX,
        SEMANTIC,
        RUNTIME
    };
    
    Error(Type t, const std::string& msg, int ln = 0, int col = 0)
        : type(t), message(msg), line(ln), column(col) {}
    
    Type type;
    std::string message;
    int line;
    int column;
};

class ErrorReporter {
public:
    static ErrorReporter& getInstance();
    
    void report(const Error& error);
    void clear();
    bool hasErrors() const;
    const std::vector<Error>& getErrors() const;
    
private:
    ErrorReporter() = default;
    std::vector<Error> errors;
};

} // namespace OroScript

#endif // OROSCRIPT_UTILS_ERRORS_H

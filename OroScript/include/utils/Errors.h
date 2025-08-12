#ifndef ERRORS_H
#define ERRORS_H

#include <stdexcept>
#include <string>

class SyntaxError : public std::runtime_error {
public:
    SyntaxError(const std::string& msg) : std::runtime_error(msg) {}
};

#endif
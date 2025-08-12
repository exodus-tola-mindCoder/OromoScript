#include <iostream>
#include <fstream>
#include <string>
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "semantic/SemanticAnalyzer.h"
#include "evaluator/Evaluator.h"
#include "utils/Errors.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: afaancode <file.oro>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::string source((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    try {
        // Lex
        Lexer lexer(source);
        std::vector<Token> tokens = lexer.lex();

        // Parse
        Parser parser(tokens);
        std::unique_ptr<Node> ast = parser.parse();

        // Semantic analysis
        SemanticAnalyzer analyzer;
        analyzer.analyze(ast.get());

        // Evaluate (interpret)
        Evaluator evaluator;
        evaluator.evaluate(ast.get());

        std::cout << "Execution complete." << std::endl;
    } catch (const SyntaxError& e) {
        std::cerr << "Syntax error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
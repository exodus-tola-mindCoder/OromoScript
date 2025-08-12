#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/lexer/Lexer.h"
#include "../include/parser/Parser.h"
#include "../include/semantic/SemanticAnalyzer.h"
#include "../include/evaluator/Evaluator.h"

using namespace OroScript;

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return "";
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.oro>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string source = readFile(filename);
    
    if (source.empty()) {
        return 1;
    }
    
    try {
        // Lexical analysis
        Lexer lexer(source);
        auto tokens = lexer.tokenize();
        
        // Parsing
        Parser parser(tokens);
        auto program = parser.parse();
        
        // Semantic analysis
        SemanticAnalyzer analyzer;
        analyzer.analyze(*program);
        
        // Evaluation
        Evaluator evaluator;
        evaluator.evaluate(*program);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include "Lexer.hpp"
#include "Token.hpp"

using namespace std;

void run(const string& source) {
    Lexer lexer(source);
    vector<Token> tokens = lexer.scanTokens();

    // For now, just print the tokens to see the output
    for (const auto& token : tokens) {
        cout << token.toString() << endl;
    }
}

int main(int argc, char *argv[])
{
    cout << "--- OroScript Lexer Test ---" << endl << endl;

    string source = R"(
        // Sagantaa herregaa salphaa
        maqaa x = 10;
        maqaa y = 20.5;
        maqaa jecha = "Nagaa Addunyaa!";

        yoo (x > 5) {
            baasi(jecha);
        }
    )";
    run(source);

    return 0;
}
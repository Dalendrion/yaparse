#include <iostream>
#include <vector>
#include <string>
#include "Lexer.hpp"
#include "AST.hpp"
#include "util.h"
using namespace std;

int main(int argc, const char **argv)
{
    Lexer myLex = Lexer();
    
    for (int i = 1; i < argc; i++)
    {
        vector<string> fileLines = getFileLines(*(argv + i), '\n');
        
        for (size_t lnInd = 0; lnInd < fileLines.size(); lnInd++)
        {
            myLex.tokenize(fileLines.at(lnInd));
        }
    }
    
    AST myAST = AST();
    myAST.build(myLex.getTokenList());
    
    return 0;
}
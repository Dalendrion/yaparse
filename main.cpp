#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Lexer.hpp"
using namespace std;

vector<string> getFileLines(const char *filePath, char explodeOn)
{
    vector<string> lines;
    
    ifstream inputFile;
    
    inputFile.open(filePath);
    
    if (inputFile.is_open())
    {
        string tmpLn = "";
        
        char tmpChar;
        
        while (inputFile.get(tmpChar))
        {
            if (tmpChar != explodeOn)
            {
                tmpLn = tmpLn + tmpChar;
            }
            else
            {
                lines.push_back(tmpLn);
                tmpLn = "";
            }
        }
        
        inputFile.close();
    }
    
    return lines;
}

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
        myLex.printList();
    }
    
    return 0;
}
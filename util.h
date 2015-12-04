#ifndef __UTIL_H__
#define __UTIL_H__

#include <fstream>
#include <vector>
#include <string>

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

#endif
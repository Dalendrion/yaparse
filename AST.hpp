#ifndef __AST_H__
#define __AST_H__

#include <iostream>
#include <vector>
#include "ASTNode.hpp"

using namespace std;

class AST
{
    public:
        AST();
        vector<ASTNode> build();
};

#endif
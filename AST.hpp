#ifndef __AST_H__
#define __AST_H__

#include <iostream>
#include <vector>
#include "yalex/Token.hpp"
#include "ASTNode.hpp"

using namespace std;

class AST
{
    public:
        AST();
        vector<ASTNode> build(vector<ListToken> tokens);
};

#endif
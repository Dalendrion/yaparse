#include "AST.hpp"

AST::AST()
{
}

vector<ASTNode> AST::build(vector<ListToken> tokens)
{
    vector<ASTNode> ASTNodes;
    
    for (size_t i = 0; i < tokens.size(); i++)
    {
        ListToken thisTok = tokens.at(i);
        
        if (!this->isToBeIgnored(thisTok))
        {            
            // TODO (Gigabyte Giant): Figure out a good way to build up an AST.
        }
    }
    
    return ASTNodes;
}

bool AST::isToBeIgnored(ListToken token)
{
    vector<string> tokensToIgnore = {
        "Whitespace",
        "Ignored",
        "Unknown"
    };
    
    for (size_t i = 0; i < tokensToIgnore.size(); i++)
    {
        if (token.getTokenType() == tokensToIgnore.at(i)) {
            return true;
        }
    }
    
    return false;
}
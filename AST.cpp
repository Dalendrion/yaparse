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
            printf("'%s' is a(n) '%s' token\n", thisTok.getTokenValue().c_str(), thisTok.getTokenType().c_str());
            
            // TODO (Gigabyte Giant): Figure out a good way to build up an AST.
        }
    }
    
    return ASTNodes;
}

bool AST::isToBeIgnored(ListToken token)
{
    if (token.getTokenType() == "Whitespace" ||
        token.getTokenType() == "Ignored" ||
        token.getTokenType() == "Unknown")
    {
        return true;
    }
    
    return false;
}
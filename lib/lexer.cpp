#ifndef LEXER
#define LEXER

#include "readSrc.h"
#include <iostream>
#include <vector>
#include <regex>
using namespace std;

class Lexer
{
  public:
    vector<string> lexems;
    vector<string>::iterator tokenPtr;
    vector<pair<regex, string>> rules;
    
    Lexer(string path)
    {
        lexems = readSrc(path);
        tokenPtr = lexems.begin();
        rules.push_back({regex("int"), "INT"});
        rules.push_back({regex("void"), "VOID"});
        rules.push_back({regex("main"), "MAIN"});
        rules.push_back({regex("(int|float|double|string|char)"), "TYPE"});
        rules.push_back({regex("begin"), "BEG"});
        rules.push_back({regex("end"), "END"});
        rules.push_back({regex("[a-zA-Z_][a-zA-Z0-9]+"), "VAR"});
        rules.push_back({regex("\\("), "RBT"});
        rules.push_back({regex("\\)"), "LBT"});
        rules.push_back({regex("if"), "IF"});
        rules.push_back({regex("printf"), "PRT"});
        rules.push_back({regex(";"), "SM"});
        rules.push_back({regex(","), "CM"});
    }

    void displayLexems()
    {
        for (string lexem : lexems)
            cout << lexem << endl;
    }

    string lexemToToken(string lexem)
    {
        for (auto rule : rules)
        {
            if (regex_match(lexem.begin(), lexem.end(), rule.first))
                return rule.second;
        }
        return lexem;
    }

    string getNextToken()
    {
        string lexem, token;
        if (tokenPtr == lexems.end())
            return "$";
        lexem = *tokenPtr;
        token = lexemToToken(lexem);
        tokenPtr++;
        return token;
    }
};

int main()
{
    Lexer lxr("src.lng");
    // lxr.displayLexems();
    for(auto lexem : lxr.lexems)
        cout << lxr.getNextToken() << endl;
}
#endif
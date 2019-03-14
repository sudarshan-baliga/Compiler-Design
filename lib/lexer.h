#ifndef LEXER
#define LEXER

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
    Lexer(string path);
    void displayLexems();
    string lexemToToken(string lexem);
    string getNextToken();
};
#endif
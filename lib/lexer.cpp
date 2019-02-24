#ifndef LEXER
#define LEXER

#include "readSrc.h"
#include <iostream>
#include <vector>
using namespace std;

class Lexer
{
  public:
    vector<string> lexems;
    vector<string>::iterator tokenPtr;
    Lexer(string path)
    {
        lexems = readSrc(path);
    }

    void displayLexems()
    {
        for (string lexem : lexems)
            cout << lexem << endl;
    }
};

int main()
{
    Lexer lxr("src.lng");
    lxr.displayLexems();
}
#endif
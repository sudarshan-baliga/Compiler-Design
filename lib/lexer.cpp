#ifndef LEXER
#define LEXER

#include "readSrc.h"
#include <iostream>
#include <vector>
using namespace std;

class Lexer
{
    vector<string> words;
    vector<string>::iterator tokenPtr;
    Lexer(string path)
    {
        words = readSrc(path);
    }
    
};
#endif
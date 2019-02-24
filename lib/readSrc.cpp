#include "readSrc.h"
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> readSrc(string path)
{
    ifstream file;
    vector<string> words;
    file.open(path);
    string lexem;
    char ch;
    while (file >> noskipws >> ch)
    {
        if (ch != ' ' && ch != '\n' && ch != '\t')
        {
            if (ch == ',' || ch == ';' || ch == '(' || ch == ')')
            {
                if (lexem != "")
                    words.push_back(lexem);
                lexem = ch;
                words.push_back(lexem);
                lexem = "";
            }
            else
            {
                lexem += ch;
            }
            continue;
        }
        if (lexem != "")
            words.push_back(lexem);
        lexem = "";
    }
    return words;
}
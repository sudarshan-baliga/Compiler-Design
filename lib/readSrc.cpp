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
    string lexem = "", relopLexem = "";
    char ch;
    while (file >> noskipws >> ch)
    {
        if (ch != ' ' && ch != '\n' && ch != '\t')
        {
            if (ch == ',' || ch == ';' || ch == '(' || ch == ')')
            {
                if (lexem != "")
                    words.push_back(lexem);
                if (relopLexem != "")
                    words.push_back(relopLexem);
                lexem = ch;
                words.push_back(lexem);
                lexem = "";
                relopLexem = "";
            }
            else if (ch == '+' || ch == '-' || ch == '/' || ch == '*' | ch == '%')
            {
                if (lexem != "")
                    words.push_back(lexem);
                if (relopLexem != "")
                    words.push_back(relopLexem);
                lexem = ch;
                words.push_back(lexem);
                lexem = "";
                relopLexem = "";
            }
            else if (ch == '=' || ch == '<' || ch == '>' || ch == '!')
            {
                if (lexem != "")
                    words.push_back(lexem);
                lexem = "";
                relopLexem += ch;
            }
            else
            {
                if (relopLexem != "")
                    words.push_back(relopLexem);
                relopLexem = "";
                lexem += ch;
            }
            continue;
        }
        if (lexem != "")
            words.push_back(lexem);
        if (relopLexem != "")
            words.push_back(relopLexem);
        lexem = "";
        relopLexem = "";
    }
    if (lexem != "")
        words.push_back(lexem);
    if (relopLexem != "")
        words.push_back(relopLexem);

    return words;
}

#include "readSrc.h"
#include <fstream>
#include <vector>
using namespace std;

vector<string> readSrc(string path)
{
    ifstream file;
    vector<string> words;
    file.open(path);
    string  word;
    while (file >> word)
        words.push_back(word);
    return words;
}
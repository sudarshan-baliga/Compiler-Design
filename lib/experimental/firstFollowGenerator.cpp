#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream productions;
    productions.open("productions.txt");
    string line, word;
    while (getline(productions, line))
    {
        istringstream iss(line);
        while (line >> word)
            cout << word << endl;
    }
}
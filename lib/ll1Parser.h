#ifndef LL1PARSER
#define LL1PARSER
#include <iostream>
#include <vector>
using namespace std;

class Ll1Parser{
    public:
        vector<string> stk;
        int parser();
        bool success;
        void printStack();
};

#endif
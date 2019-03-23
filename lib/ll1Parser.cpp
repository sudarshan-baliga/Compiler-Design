#include "ll1Parser.h"
#include <iostream>
#include <stack>
#include "parsingTable.h"
#include "lexer.h"

using namespace std;

void logError(string stkSym, string token)
{
    cout << "There was an error stack symbol and token " << stkSym << " " << token << endl;
}

void Ll1Parser::printStack()
{
    for (string str : stk)
    {
        cout << str << " ";
    }
    cout << "|";
}

int Ll1Parser::parser()
{
    string nxtTkn;
    vector<string> prod;
    ParsingTable ParseTable;
    stk.push_back("$");
    stk.push_back("S");
    Lexer lex("src.lng");
    while (true)
    {
        nxtTkn = lex.getNextToken();
        // cout << "Next token is " << nxtTkn << endl;
        // if next token is terminal
        if (stk.back() == nxtTkn)
        {
            printStack();
            cout << "\t" << nxtTkn << "\t";
            cout << "Matched " << nxtTkn << endl;
            stk.pop_back();
        }
        // if it is non terminal
        else {
            // get to the correct row in parser table
            if(!ParseTable.table[{stk.back(), nxtTkn}].empty())
            {
                prod = ParseTable.table[{stk.back(), nxtTkn}];
                // remove the existing symbol from stack
                stk.pop_back();
                // push the production in revese order
                for(auto it = prod.rbegin(); it != prod.rend(); it++)
                {
                    stk.push_back(*it);
                }
                // check if there is a match between top and input symbol
                if(stk.back() == nxtTkn)
                    stk.pop_back();
                else logError(stk.back(), nxtTkn);
                printStack();
                stk.pop_back();
                cout << endl;
            }
            else
            {
                logError(stk.back(), nxtTkn);
            }
            
        }
        if(nxtTkn == "$")
            return 0;
    }
    return 0;
}
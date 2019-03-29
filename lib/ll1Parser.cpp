#include "ll1Parser.h"
#include <iostream>
#include <stack>
#include "parsingTable.h"
#include "lexer.h"

using namespace std;

void logError(string stkSym, string token)
{
    cout << "\033[1;31m There was an error stack symbol and token " << stkSym << " " << token << "\033[0m\n";
}

void Ll1Parser::printStack()
{

    cout << "\033[1;36m" << stk.back() << "\033[0m";
    //    cout << "\033[1;36m";
    //     for(auto ele: stk)
    //         cout << ele << " ";
    //     cout << "\033[0m";
}

int Ll1Parser::parser()
{
    string nxtTkn;
    vector<string> prod;
    ParsingTable ParseTable;
    stk.push_back("$");
    stk.push_back("S");
    Lexer lex("src.lng");
    nxtTkn = lex.getNextToken();
    cout << "\033[1;36mStackTop\033[0m "
         << "\033[1;33mInput\033[0m "
         << "\033[1;32mOutput\033[0m\n";
    while (true)
    {
        if (nxtTkn == "$")
        {
            printStack();
            cout << "\t$\t" << endl;
            break;
        }

        printStack();
        cout << "\t\033[1;33m" << nxtTkn << "\033[0m\t";

        // if next token is terminal
        if (stk.back() == nxtTkn)
        {
            cout << "\033[1;32mMatched " << nxtTkn << "\033[0m";
            stk.pop_back();
            nxtTkn = lex.getNextToken();
        }

        // if it is non terminal
        else
        {
            // get to the correct row in parser table
            if (!ParseTable.table[{stk.back(), nxtTkn}].empty())
            {
                prod = ParseTable.table[{stk.back(), nxtTkn}];
                if (*prod.rbegin() == "SYNCH")
                {
                    cout << "\033[1;32m" << stk.back() << " -> ";
                    cout << "SYNCH\033[0m\n";
                    if (stk.size() == 1)
                    {
                        nxtTkn = lex.getNextToken();
                        continue;
                    }
                    stk.pop_back();
                    continue;
                }

                // push the production in revese order
                cout << "\033[1;32m" << stk.back() << " -> ";
                for (auto it = prod.begin(); it != prod.end(); it++)
                {
                    cout << *it << " ";
                }
                // remove the existing symbol from stack
                stk.pop_back();
                //push the production  in revrse order
                if (*(prod.rbegin()) == " ")
                    cout << "\u03BB";
                else
                    for (auto it = prod.rbegin(); it != prod.rend(); it++)
                    {
                        if (*it != " ")
                            stk.push_back(*it);
                    }
                cout << "\033[0m";
                // check if there is a match between top and input symbol
            }
            else
            {
                cout << "\033[1;31mSkipping " << nxtTkn << "\033[0m";
                nxtTkn = lex.getNextToken();
            }
        }
        cout << endl;
    }
    return 0;
}
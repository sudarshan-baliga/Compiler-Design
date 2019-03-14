#include "lexer.h"

int main()
{
   Lexer s("src.lng");
   cout << s.getNextToken();
}
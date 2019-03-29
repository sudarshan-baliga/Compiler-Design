#include "./lib/ll1Parser.h"
#include "./lib/parsingTable.h"

int main()
{
    Ll1Parser Parser;
    ParsingTable Table;
    cout << "Parsing table is : \n";
    Table.showParsingTable();
    cout << "\033[1;35m--*--*--*--*--*--*--*--*--*--*--*--*--*--*\n\033[0m";
    cout << "Parsing of the given language :\n";
    Parser.parser();
    cout << "\033[1;35m--*--*--*--*--*--*--*--*--*--*--*--*--*--*\n\033[0m";
}

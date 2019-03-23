#include "parsingTable.h"

ParsingTable::ParsingTable()
{
    table[{"S", "type"}] = {"type", "main", "lbt", "rbt", "beg", "CODE",
                            "end"};
    table[{"CODE", "type"}] = {"DEC", "CODE"};
    table[{"CODE", "if"}] = {"IF_STMT", "CODE"};
    table[{"IF_STMT", "type"}] = {"type", "main", "lbt", "rbt", "beg", "CODE"
                                                                       "end"};
}
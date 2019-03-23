#ifndef PARSINGTABLE
#define PARSINGTABLE
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class ParsingTable
{
public:
  map<pair<string, string>, vector<string>> table;
  ParsingTable();
};
#endif
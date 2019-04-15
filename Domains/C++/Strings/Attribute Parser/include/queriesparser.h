#ifndef QUERIESPARSER_H
#define QUERIESPARSER_H

#include <vector>
#include <string>
#include <memory>

using namespace std;

class Query;

class QueriesParser
{
  public:
    QueriesParser(vector<string> lines);
    ~QueriesParser() = default;

    vector<unique_ptr<Query>> parse();

    unique_ptr<Query> parseQuery(string line);
    vector<string> parseTagNames(string line);

  private:
    vector<string> _lines;
};

#endif // QUERIESPARSER_H
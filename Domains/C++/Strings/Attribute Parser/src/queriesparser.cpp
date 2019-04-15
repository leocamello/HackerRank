#include <algorithm>

#include "query.h"
#include "attributequery.h"
#include "elementquery.h"
#include "queriesparser.h"

QueriesParser::QueriesParser(vector<string> lines)
    : _lines(lines)
{
}

vector<unique_ptr<Query>> QueriesParser::parse()
{
    vector<unique_ptr<Query>> queries;

    for (const auto &line : _lines)
    {
        queries.push_back(parseQuery(line));
    }

    return queries;
}

unique_ptr<Query> QueriesParser::parseQuery(string line)
{
    auto found = line.find('~');
    if (found == line.npos)
    {
        return make_unique<Query>();
    }

    auto attributeName = line.substr(found + 1, line.size() - 1);
    auto attributeQuery = make_unique<AttributeQuery>(attributeName);

    vector<string> tagNames = parseTagNames(line.substr(0, found));

    unique_ptr<Query> currentQuery(move(attributeQuery));

    for (auto it = rbegin(tagNames); it != rend(tagNames); it++)
    {
        currentQuery = make_unique<ElementQuery>((*it), move(currentQuery));
    }

    return currentQuery;
}

vector<string> QueriesParser::parseTagNames(string line)
{
    vector<string> tagNames;

    for (auto found = line.find('.'); found != line.npos; found = line.find('.'))
    {
        tagNames.push_back(line.substr(0, found));
        line = line.substr(found + 1, line.size() - 1);
    }

    tagNames.push_back(line);

    return tagNames;
}
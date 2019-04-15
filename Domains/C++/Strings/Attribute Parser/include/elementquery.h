#ifndef ELEMENTQUERY_H
#define ELEMENTQUERY_H

#include <string>
#include <memory>

#include "query.h"

using namespace std;

class ElementQuery final : public Query
{
    public:
        ElementQuery(string tagName, unique_ptr<Query> query);

        string execute(const unique_ptr<HrmlElement>& element) override;
        string execute(const vector<unique_ptr<HrmlElement>>& elements) const;

    private:
        string _tagName;
        unique_ptr<Query> _query;
};

#endif // ELEMENTQUERY_H
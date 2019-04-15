#include "hrmlelement.h"
#include "elementquery.h"

ElementQuery::ElementQuery(string tagName, unique_ptr<Query> query)
: _tagName(tagName), _query(move(query))
{
}

string ElementQuery::execute(const unique_ptr<HrmlElement>& element)
{
    return execute(element->getChildren());
}

string ElementQuery::execute(const vector<unique_ptr<HrmlElement>>& elements) const
{
    for(const auto& element : elements)
    {
        if (_tagName == element->getTagName()) 
        {
            return _query->execute(element);
        }
    }    

    return Query::NOT_FOUND;
}
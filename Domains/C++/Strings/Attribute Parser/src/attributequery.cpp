#include "hrmlelement.h"
#include "hrmlattribute.h"
#include "attributequery.h"

AttributeQuery::AttributeQuery(string attributeName)
    : _attributeName(attributeName)
{
}

string AttributeQuery::execute(const unique_ptr<HrmlElement>& element)
{
    for (const auto &attribute : element->getAttributes())
    {
        if (attribute.getName() == _attributeName)
        {
            return attribute.getValue();
        }
    }

    return Query::execute(element);
}
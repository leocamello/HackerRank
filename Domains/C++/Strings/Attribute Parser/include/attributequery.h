#ifndef ATTRIBUTEQUERY_H
#define ATTRIBUTEQUERY_H

#include <memory>

#include "query.h"

using namespace std;

class AttributeQuery final : public Query
{
    public:
        AttributeQuery(string attributeName);

        virtual string execute(const unique_ptr<HrmlElement>& element) override;

    private:
        string _attributeName;
};

#endif // ATTRIBUTEQUERY_H
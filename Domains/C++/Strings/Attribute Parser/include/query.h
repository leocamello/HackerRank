#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class HrmlElement;

class Query
{
    public:
        static const string NOT_FOUND;
        
        virtual ~Query() = default;
        virtual string execute(const unique_ptr<HrmlElement>& element);
};

#endif // QUERY_H
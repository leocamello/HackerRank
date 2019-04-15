#include "query.h"

const string Query::NOT_FOUND = "Not Found!";

string Query::execute(const unique_ptr<HrmlElement>& element)
{
    return Query::NOT_FOUND;
}

#include "hrmlattribute.h"

HrmlAttribute::HrmlAttribute(string name, string value)
    : _name(name), _value(value)
{
}

const string HrmlAttribute::getName() const
{
    return _name;
}

const string HrmlAttribute::getValue() const
{
    return _value;
}
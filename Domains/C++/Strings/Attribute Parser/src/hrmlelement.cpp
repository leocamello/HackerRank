#include "hrmlattribute.h"
#include "hrmlelement.h"

HrmlElement::HrmlElement(string tagName, vector<HrmlAttribute> attributes)
    : _tagName(tagName), _attributes(attributes), _parent(nullptr)
{
}

const string HrmlElement::getTagName() const
{
    return _tagName;
}

const vector<HrmlAttribute> HrmlElement::getAttributes() const
{
    return _attributes;
}

HrmlElement* HrmlElement::getParent() const
{
    return _parent;
}

void HrmlElement::setParent(HrmlElement *parent)
{
    _parent = parent;
}

void HrmlElement::addChild(unique_ptr<HrmlElement> child)
{
    _children.push_back(move(child));
}

const vector<unique_ptr<HrmlElement>>& HrmlElement::getChildren() const
{
    return _children;
}
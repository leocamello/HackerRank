#ifndef HRMLELEMENT_H
#define HRMLELEMENT_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class HrmlAttribute;

class HrmlElement
{
  public:
    HrmlElement(string tagName, vector<HrmlAttribute> attributes);
    ~HrmlElement() = default;

    const string getTagName() const;
    const vector<HrmlAttribute> getAttributes() const;

    HrmlElement *getParent() const;
    void setParent(HrmlElement *parent);

    void addChild(unique_ptr<HrmlElement> child);
    const vector<unique_ptr<HrmlElement>>& getChildren() const;

  private:
    string _tagName;
    vector<HrmlAttribute> _attributes;
    HrmlElement *_parent;
    vector<unique_ptr<HrmlElement>> _children;
};

#endif // HRMLELEMENT_H
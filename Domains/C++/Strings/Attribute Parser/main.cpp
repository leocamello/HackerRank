#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <memory>

using namespace std;

class HrmlAttribute
{
  public:
    HrmlAttribute(string name, string value)
    {
        _name = name;
        _value = value;
    }

    ~HrmlAttribute() {}

    const string getName() const { return _name; }
    const string getValue() const { return _value; }

  private:
    string _name, _value;
};

class HrmlElement
{
  public:
    HrmlElement(string tagName, vector<HrmlAttribute> attributes)
    {
        _tagName = tagName;
        _attributes = attributes;
    }

    ~HrmlElement() {}

    const string getTagName() const { return _tagName; }

    shared_ptr<HrmlElement> getParent() const { return _parent.lock(); }
    void setParent(shared_ptr<HrmlElement> parent) { _parent = parent; }

    void addChild(shared_ptr<HrmlElement> child) { _children.push_back(child); }
    const vector<shared_ptr<HrmlElement>> getChildren() const { return _children; }

    const vector<HrmlAttribute> getAttributes() const { return _attributes; }

  private:
    string _tagName;
    weak_ptr<HrmlElement> _parent;
    vector<shared_ptr<HrmlElement>> _children;
    vector<HrmlAttribute> _attributes;
};

string getName(string& line)
{
    // Get tag name
    auto space_pos = line.find(' ');
    space_pos = space_pos == string::npos ? line.size() : space_pos;
    string tag_name = line.substr(0, space_pos);

    // Remove tag name
    auto first_pos = space_pos == line.size() ? space_pos : space_pos + 1;
    line = line.substr(first_pos, line.size() - space_pos);

    return tag_name;
}

HrmlAttribute getAttribute(string& line)
{
    // Get attribute name
    auto space_pos = line.find(' ');
    string attr_name = line.substr(0, space_pos);

    // Remove attribute name
    auto first_pos = space_pos + 1;
    line = line.substr(first_pos, line.size() - space_pos);

    // Get and remove equal sign
    space_pos = line.find(' ');
    line.substr(0, space_pos);
    first_pos = space_pos + 1;
    line = line.substr(first_pos, line.size() - space_pos);

    // Get attribute value
    space_pos = line.find(' ');
    space_pos = space_pos == string::npos ? line.size() : space_pos;
    string attr_value = line.substr(0, space_pos);
    attr_value = attr_value.substr(1, attr_value.size() - 2);

    // Remove attribute value
    first_pos = space_pos == line.size() ? space_pos : space_pos + 1;
    line = line.substr(first_pos, line.size() - space_pos);

    return HrmlAttribute(attr_name, attr_value);
}

vector<HrmlAttribute> getAttributes(string& line)
{
    vector<HrmlAttribute> attributes;

    while (!line.empty())
    {
        attributes.push_back(getAttribute(line));
    }

    return attributes;
}

shared_ptr<HrmlElement> parseStartingTag(string line)
{
    // Remove < and >
    line = line.substr(1, line.size() - 2);

    auto name = getName(line);
    auto attributes = getAttributes(line);

    return make_shared<HrmlElement>(name, attributes);
}

string parseEndingTag(string line)
{
    return line.substr(2, line.size() - 3);
}

string executeQuery(string line, vector<shared_ptr<HrmlElement>> elements)
{
    vector<shared_ptr<HrmlElement>> search_list = elements;

    for(auto found = line.find('.'); found != line.npos; found = line.find('.'))
    {
        string tag_name = line.substr(0, found);
        auto it = find_if(search_list.begin(), search_list.end(),
                          [tag_name](shared_ptr<HrmlElement> element) {
                              return element->getTagName() == tag_name;
                          });

        if (it != search_list.end())
        {
            search_list = (*it)->getChildren();
        }
        else
        {
            return "Not Found!";
        }

        line = line.substr(found + 1, line.size() - found);
    }

    auto found = line.find('~');
    string tag_name = line.substr(0, found);
    string attr_name = line.substr(found + 1, line.size() - found);
    auto it = find_if(search_list.begin(), search_list.end(),
                      [tag_name](shared_ptr<HrmlElement> element) {
                          return element->getTagName() == tag_name;
                      });

    if (it != search_list.end())
    {
        auto attr_list = (*it)->getAttributes();
        auto attr_it = find_if(attr_list.begin(), attr_list.end(),
                               [attr_name](const HrmlAttribute &attr) {
                                   return attr.getName() == attr_name;
                               });

        if (attr_it != attr_list.end())
        {
            return (*attr_it).getValue();
        }
    }

    return "Not Found!";
}

int main()
{
    int N, Q;
    cin >> N >> Q;

    string line;
    getline(cin, line);

    shared_ptr<HrmlElement> current(nullptr);
    vector<shared_ptr<HrmlElement>> elements;

    while (N--)
    {

        getline(cin, line);

        if (line[0] == '<' && line[1] != '/' && line[line.size() - 1] == '>')
        {
            auto element = parseStartingTag(line);
            if (current == nullptr)
            {
                elements.push_back(element);
            }
            else
            {
                element->setParent(current);
                current->addChild(element);
            }
            current = element;
        }
        else if (line[0] == '<' && line[1] == '/' &&
                 line[line.size() - 1] == '>')
        {
            auto tag_name = parseEndingTag(line);
            if (current->getTagName() == tag_name)
            {
                current = current->getParent();
            }
            else
            {
                cout << "Error: Ending Tag cannot be different from current element tag name." << endl;
            }
        }
    }

    while (Q--)
    {
        getline(cin, line);
        cout << executeQuery(line, elements) << endl;
    }

    return 0;
}

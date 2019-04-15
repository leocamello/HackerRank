#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class HrmlAttribute
{
  public:
    HrmlAttribute(string name, string value) : _name(name), _value(value) {}
    ~HrmlAttribute() = default;

    const string getName() const { return _name; }
    const string getValue() const { return _value; }

  private:
    string _name, _value;
};

class HrmlElement
{
  public:
    HrmlElement(string tagName, vector<HrmlAttribute> attributes)
        : _tagName(tagName), _attributes(attributes), _parent(nullptr) {}
    ~HrmlElement() = default;

    const string getTagName() const { return _tagName; }
    const vector<HrmlAttribute> getAttributes() const { return _attributes; }

    HrmlElement *getParent() const { return _parent; }
    void setParent(HrmlElement *parent) { _parent = parent; }

    void addChild(unique_ptr<HrmlElement> child)
    {
        _children.push_back(move(child));
    }
    const vector<unique_ptr<HrmlElement>> &getChildren() const
    {
        return _children;
    }

  private:
    string _tagName;
    vector<HrmlAttribute> _attributes;
    HrmlElement *_parent;
    vector<unique_ptr<HrmlElement>> _children;
};

class HrmlParser
{
  public:
    HrmlParser(vector<string> lines) : _lines(lines){};
    ~HrmlParser() = default;

    vector<unique_ptr<HrmlElement>> parse()
    {
        HrmlElement *current(nullptr);
        vector<unique_ptr<HrmlElement>> elements;

        for (auto &&line : _lines)
        {
            if (line.front() == '<' && line.back() == '>')
            {
                line = line.substr(1, line.size() - 2);

                if (line.front() != '/')
                {
                    auto element = parseStartingTag(line);
                    auto tmp = element.get();

                    if (current == nullptr)
                    {
                        elements.push_back(move(element));
                    }
                    else
                    {
                        element->setParent(current);
                        current->addChild(move(element));
                    }

                    current = tmp;
                }
                else
                {
                    auto tag_name = parseEndingTag(line);
                    if (current->getTagName() == tag_name)
                    {
                        current = current->getParent();
                    }
                    else
                    {
                        // cout << "Error: Ending Tag cannot be different from current
                        // element tag name." << endl;
                    }
                }
            }
            else
            {
                // cout << "Error: At least one line is not formatted correctly." <<
                // endl;
            }
        }

        return elements;
    }

    unique_ptr<HrmlElement> parseStartingTag(string line)
    {
        auto name = getName(line);
        auto attributes = getAttributes(line);

        // return make_unique<HrmlElement>(name, attributes);
        return unique_ptr<HrmlElement>(new HrmlElement(name, attributes));
    }

    string parseEndingTag(string line) { return line.substr(1, line.size() - 1); }

    string getName(string &line)
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

    vector<HrmlAttribute> getAttributes(string &line)
    {
        vector<HrmlAttribute> attributes;

        while (!line.empty())
        {
            attributes.push_back(getAttribute(line));
        }

        return attributes;
    }

    HrmlAttribute getAttribute(string &line)
    {
        // Get attribute name
        auto space_pos = line.find(' ');
        string attr_name = line.substr(0, space_pos);

        // Remove attribute name
        line = line.substr(space_pos + 1, line.size() - space_pos);

        // Get and remove equal sign
        space_pos = line.find(' ');
        line.substr(0, space_pos);
        line = line.substr(space_pos + 1, line.size() - space_pos);

        // Get attribute value
        space_pos = line.find(' ');
        space_pos = space_pos == string::npos ? line.size() : space_pos;
        string attr_value = line.substr(0, space_pos);
        attr_value = attr_value.substr(1, attr_value.size() - 2);

        // Remove attribute value
        auto first_pos = space_pos == line.size() ? space_pos : space_pos + 1;
        line = line.substr(first_pos, line.size() - space_pos);

        return {attr_name, attr_value};
    }

  private:
    vector<string> _lines;
};

class Query
{
  public:
    static const string NOT_FOUND;

    virtual ~Query() = default;

    virtual string execute(const unique_ptr<HrmlElement> &element) const
    {
        return Query::NOT_FOUND;
    }

    virtual string
    execute(const vector<unique_ptr<HrmlElement>> &elements) const
    {
        return Query::NOT_FOUND;
    }
};

const string Query::NOT_FOUND = "Not Found!";

class AttributeQuery final : public Query
{
  public:
    AttributeQuery(string attributeName) : _attributeName(attributeName) {}

    virtual string
    execute(const unique_ptr<HrmlElement> &element) const override
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

  private:
    string _attributeName;
};

class ElementQuery final : public Query
{
  public:
    ElementQuery(string tagName, unique_ptr<Query> query)
        : _tagName(tagName), _query(move(query)) {}

    string execute(const unique_ptr<HrmlElement> &element) const override
    {
        return execute(element->getChildren());
    }

    string
    execute(const vector<unique_ptr<HrmlElement>> &elements) const override
    {
        for (const auto &element : elements)
        {
            if (_tagName == element->getTagName())
            {
                return _query->execute(element);
            }
        }

        return Query::NOT_FOUND;
    }

  private:
    string _tagName;
    unique_ptr<Query> _query;
};

class QueriesParser
{
  public:
    QueriesParser(vector<string> lines) : _lines(lines) {}
    ~QueriesParser() = default;

    vector<unique_ptr<Query>> parse()
    {
        vector<unique_ptr<Query>> queries;

        for (const auto &line : _lines)
        {
            queries.push_back(parseQuery(line));
        }

        return queries;
    }

    unique_ptr<Query> parseQuery(string line)
    {
        auto found = line.find('~');
        if (found == line.npos)
        {
            // return make_unique<Query>();
            return unique_ptr<Query>();
        }

        auto attributeName = line.substr(found + 1, line.size() - 1);
        // auto attributeQuery = make_unique<AttributeQuery>(attributeName);
        auto attributeQuery =
            unique_ptr<AttributeQuery>(new AttributeQuery(attributeName));

        vector<string> tagNames = parseTagNames(line.substr(0, found));

        unique_ptr<Query> currentQuery(move(attributeQuery));

        for (auto it = tagNames.rbegin(); it != tagNames.rend(); it++)
        {
            // currentQuery = make_unique<ElementQuery>((*it), move(currentQuery));
            currentQuery =
                unique_ptr<ElementQuery>(new ElementQuery((*it), move(currentQuery)));
        }

        return currentQuery;
    }

    vector<string> parseTagNames(string line)
    {
        vector<string> tagNames;

        for (auto found = line.find('.'); found != line.npos;
             found = line.find('.'))
        {
            tagNames.push_back(line.substr(0, found));
            line = line.substr(found + 1, line.size() - 1);
        }

        tagNames.push_back(line);

        return tagNames;
    }

  private:
    vector<string> _lines;
};

int main()
{
    int N, Q;
    cin >> N >> Q;

    string line;
    getline(cin, line);

    vector<string> lines;

    while (N--)
    {
        getline(cin, line);
        lines.push_back(line);
    }

    HrmlParser hrml_parser(lines);
    auto elements = move(hrml_parser.parse());

    lines.clear();

    while (Q--)
    {
        getline(cin, line);
        lines.push_back(line);
    }

    QueriesParser queries_parser(lines);
    auto queries = queries_parser.parse();

    for (const auto &query : queries)
    {
        cout << query->execute(elements) << endl;
    }

    return 0;
}

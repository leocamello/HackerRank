#include "hrmlelement.h"
#include "hrmlattribute.h"
#include "hrmlparser.h"

HrmlParser::HrmlParser(vector<string> lines)
    : _lines(lines)
{
}

vector<unique_ptr<HrmlElement>> HrmlParser::parse()
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
                    // cout << "Error: Ending Tag cannot be different from current element tag name." << endl;
                }
            }
        }
        else
        {
            // cout << "Error: At least one line is not formatted correctly." << endl;
        }   
    }

    return elements;
}

unique_ptr<HrmlElement> HrmlParser::parseStartingTag(string line)
{
    auto name = getName(line);
    auto attributes = getAttributes(line);

    return make_unique<HrmlElement>(name, attributes);
}

string HrmlParser::parseEndingTag(string line)
{
    return line.substr(1, line.size() - 1);
}

string HrmlParser::getName(string &line)
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

vector<HrmlAttribute> HrmlParser::getAttributes(string &line)
{
    vector<HrmlAttribute> attributes;

    while (!line.empty())
    {
        attributes.push_back(getAttribute(line));
    }

    return attributes;
}

HrmlAttribute HrmlParser::getAttribute(string &line)
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

    return { attr_name, attr_value };
}
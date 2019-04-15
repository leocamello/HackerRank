#ifndef HRMLPARSER_H
#define HRMLPARSER_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class HrmlElement;
class HrmlAttribute;

class HrmlParser
{
  public:
    HrmlParser(vector<string> lines);
    ~HrmlParser() = default;

    vector<unique_ptr<HrmlElement>> parse();
    
    unique_ptr<HrmlElement> parseStartingTag(string line);
    string parseEndingTag(string line);
    string getName(string &line);
    vector<HrmlAttribute> getAttributes(string &line);
    HrmlAttribute getAttribute(string &line);

  private:
    vector<string> _lines;
};

#endif // HRMLPARSER_H
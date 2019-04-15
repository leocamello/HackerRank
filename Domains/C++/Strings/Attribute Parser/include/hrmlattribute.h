#ifndef HRMLATTRIBUTE_H
#define HRMLATTRIBUTE_H

#include <string>

using namespace std;

class HrmlAttribute
{
  public:
    HrmlAttribute(string name, string value);
    ~HrmlAttribute() = default;

    const string getName() const;
    const string getValue() const;

  private:
    string _name, _value;
};

#endif // HRMLATTRIBUTE_H
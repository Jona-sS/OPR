#include "person.h"
#include <iostream>

using namespace std;

Person::Person(const string& name, int age) : _name{name}, _age{age} {}

const std::string& Person::GetName() const
{
    return _name;
}

int Person::GetAge() const
{
  return _age;
}

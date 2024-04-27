#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

class Person
{
public:
    Person(const std::string& name, int age);

    const std::string& GetName() const;
    int GetAge() const;
private:
    const std::string _name;
    int _age;
};

#endif

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "person.h"
#include <string>
#include <vector>

class Course;

///
/// Einfachstes Vererbung Beispiel:
/// 
/// Der Klasse "Student" erbt alle Methoden und Member variablen on Basis Klasse "Person".
/// Oder kann man sagen: "Student" ist "Person".
///

class Student : public Person
{
public:
    Student(const std::string& name, int age);

    double GetAverageGrade() const;

    void AddCourse(const Course* course, double grade);
private:
    std::vector<const Course*> _courses;
    std::vector<double>  _grades;
};

#endif

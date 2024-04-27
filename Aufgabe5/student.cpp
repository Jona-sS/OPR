#include "student.h"
#include "course.h"
#include <numeric>

/// Ihre Code 1 (anfang)
///
///  Bitte implementieren Sie den Konstruktor
///   
Student::Student(const std::string& name, int age) : Person(name, age) {};
/*Student(const std::string& name, int age){
    Person::Person(const string& name, int age);
}
*/
/// Ihre Code (ende)


double Student::GetAverageGrade() const
{
    double result = 0.0;

    /// Ihre Code 2 (anfang)
    ///
    ///   Bitte berechnen Sie den arithmetischen Durchschnitt aller Noten (member variable _grades)
    ///
    ///   Tip: Man kann std::accumulate nutzen statt einer einfachen Schleife
    ///        siehe auch Referenz  https://en.cppreference.com/w/cpp/algorithm/accumulate
    
    result = std::accumulate(_grades.begin(),_grades.end(),0);
    result/=_grades.size();
    /// Ihre Code (ende)

    return result;
}
 
void Student::AddCourse(const Course* course, double grade)
{
   _courses.push_back(course);
   _grades.push_back(grade);
}

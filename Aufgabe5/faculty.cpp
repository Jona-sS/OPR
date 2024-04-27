#include "faculty.h"
#include "student.h"
#include "course.h"
#include <algorithm>


Faculty::Faculty(const std::string& name) : _name{name} {} //Konstruktor

/// Ihre Code 7 (anfang)
///
///  Bitte implementieren Sie den Destruktor
///   
 Faculty::~Faculty(){}; //ggf noch delete[] ?
/// Ihre Code (ende)

void Faculty::PrepareCourse(const std::string& title)
{
	_courses.push_back(new Course(title));
}

void Faculty::HireTeacher(const std::string& name, int age)
{
	_teachers.push_back(new Person(name, age));
}

void Faculty::RegisterStudent(const std::string& name, int age)
{
/// Ihre Code 3 (anfang)
///
///  1) Bitte erstellen Sie eine neue Instanz der Klasse Student, indem Sie den Operator new verwenden
///  2) Und zu vorhandenem Vektor _students hinzuf�gen
///   
_students.push_back(new Student(name,age));
/// Ihre Code (ende)
}

const Course* Faculty::GetCourse(const std::string& title) const
{
	for (const auto course : _courses)
	{
		if (course->GetTitle() == title)
		{
			return course;
		}
	}

	return nullptr;
}

Student* Faculty::GetStudent(const std::string& name) const
{
	for (const auto student : _students)
	{
		if (student->GetName() == name)
		{
			return student;
		}
	}

	return nullptr;
}

std::vector<Student*> Faculty::GetAllStudentsSortedByAge()
{
	std::vector<Student*> result(_students);

	/// Ihre Code 4 (anfang)
	///
	///   Bitte sortieren Sie alle Studenten (lokale variable result) nach zunehmendem Alter
	///
	///   Tip: Man kann std::sort nutzen
	///        siehe auch Referenzen  http://www.cplusplus.com/reference/algorithm/sort/?kw=sort
	///                               https://en.cppreference.com/w/cpp/algorithm/sort
	std::sort (result.begin(), result.end(),cmp_StudentByAge);
	/// Ihre Code (ende)

	return result;
}

std::vector<Student*> Faculty::GetAllStudentsSortedByAvgGrade()
{
	std::vector<Student*> result(_students);

	/// Ihre Code 5 (anfang)
	///
	///   Bitte sortieren Sie alle Studenten (lokale variable result) nach durchschnittliche Note (aufsteigende Ordnung)
	///
	///   Tip: Man kann std::sort nutzen
	///        siehe auch Referenzen  http://www.cplusplus.com/reference/algorithm/sort/?kw=sort
	///                               https://en.cppreference.com/w/cpp/algorithm/sort

	std::sort (result.begin(), result.end(),cmp_StudentByAvgGrade);
	/// Ihre Code (ende)

	return result;
}

std::vector<Person*> Faculty::GetAllPersonsSortedByAge()
{
	std::vector<Person*> result;

	/// Ihre Code 6 (anfang)
	///
	///   Bitte sortieren Sie alle Studenten und Lehrer (variable result) nach zunehmendem Alter.
	///   Nicht vergessen zuerst result vorberateiten so dass alle zeigern zu Personen (von __students 
	///   und _teachers) sind enthalten.
	///
	///   Tip1: Alternative zu push_back ist insert Methode (mit erste argument result.end())
	///			siehe auch Referenz https://en.cppreference.com/w/cpp/container/vector/insert
	///   Tip2: Man kann std::sort nutzen
	///         siehe auch Referenzen  http://www.cplusplus.com/reference/algorithm/sort/?kw=sort
	///                                https://en.cppreference.com/w/cpp/algorithm/sort
	//zwei Vektoren zu einem result Vektor zusammen führen
	result.insert(result.end(),_students.begin(),_students.end());
	result.insert(result.end(),_teachers.begin(),_teachers.end());

	std::sort (result.begin(), result.end(),cmp_PersonsByAge);
	/// Ihre Code (ende)

	return result;
}
	//Compare Funktionen für Sort
	bool Faculty::cmp_StudentByAge(Student *A, Student *B){
		return A->GetAge()<B->GetAge();
	}
	bool Faculty::cmp_StudentByAvgGrade(Student* A, Student* B){
		return A->GetAverageGrade()<B->GetAverageGrade();
	}
	bool Faculty::cmp_PersonsByAge(Person* A, Person* B){
		return A->GetAge()<B->GetAge();
	}
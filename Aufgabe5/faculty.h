#ifndef _FACULTY_H_
#define _FACULTY_H_

#include <string>
#include <vector>

class Course;
class Student;
class Person;

class Faculty
{
public:
	explicit Faculty(const std::string& name);
	~Faculty();

	void HireTeacher(const std::string& name, int age);

	void PrepareCourse(const std::string& title);
	void RegisterStudent(const std::string& name, int age);

	const Course* GetCourse(const std::string& title) const;
	Student* GetStudent(const std::string& name) const;

	std::vector<Student*> GetAllStudentsSortedByAge();
	std::vector<Student*> GetAllStudentsSortedByAvgGrade();
	std::vector<Person*> GetAllPersonsSortedByAge();

private:
	const std::string _name;
	std::vector<Course*> _courses;
	std::vector<Student*> _students;
	std::vector<Person*> _teachers;
	static bool cmp_StudentByAge(Student* A, Student* B);
	static bool cmp_StudentByAvgGrade(Student* A, Student* B);
	static bool cmp_PersonsByAge(Person* A, Person* B);
};

#endif 

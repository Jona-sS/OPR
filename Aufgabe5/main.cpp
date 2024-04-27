#include <vector>
#include <iostream>
#include <algorithm>
#include "person.h"
#include "student.h"
#include "course.h"
#include "faculty.h"

///-------------------------------------------------------------------
/// Tests
///-------------------------------------------------------------------

void TestStudentAverageGrade()
{
    const Course linearalg("Linear algebra");
    const Course mechanics("Newton mechanics");
    const Course thermodyn("Thermo dynamics");

    double const linearalgGrade = 2.0;
    double const mechanicsGrade = 3.0;
    double const thermodynGrade = 5.0;
    double const expectedAverageGrade = (linearalgGrade + mechanicsGrade + thermodynGrade) / 3.0;

    Student John("John", 20);
    John.AddCourse(&linearalg, linearalgGrade);
    John.AddCourse(&mechanics, mechanicsGrade);
    John.AddCourse(&thermodyn, thermodynGrade);

    bool const ok = std::abs(John.GetAverageGrade() - expectedAverageGrade) < 1.0e-4;

    std::cout << "\tTestStudent ==> " << (ok ? "OK" : "NOK") << std::endl;
}


void TestFacultyStudentSortingByIncAge()
{
    Faculty faculty("Physics and Mathematics");
    faculty.RegisterStudent("John", 20);
    faculty.RegisterStudent("Mike", 21);
    faculty.RegisterStudent("Alice", 24);
    faculty.RegisterStudent("Anna", 22);

    const auto studentsByIncAge = faculty.GetAllStudentsSortedByAge();

    bool ok = (studentsByIncAge.size() == 4);
    for (size_t i = 1; i < studentsByIncAge.size(); ++i)
    {
        if (studentsByIncAge[i]->GetAge() < studentsByIncAge[i - 1]->GetAge())
        {
            ok = false;
            break;
        }
    }
    std::cout << "\tTestFacultyStudentSortingByIncAge ==> " << (ok ? "OK" : "NOK") << std::endl;
}

void TestFacultyPersonsSortingByIncAge()
{
    Faculty faculty("Physics and Mathematics");

    faculty.HireTeacher("Jacob", 33);
    faculty.HireTeacher("Michael", 41);

    faculty.RegisterStudent("John", 20);
    faculty.RegisterStudent("Mike", 21);
    faculty.RegisterStudent("Alice", 24);
    faculty.RegisterStudent("Anna", 22);

    const auto personsByIncAge = faculty.GetAllPersonsSortedByAge();

    bool ok = (personsByIncAge.size() == 6);
    for (size_t i = 1; i < personsByIncAge.size(); ++i)
    {
        if (personsByIncAge[i]->GetAge() < personsByIncAge[i - 1]->GetAge())
        {
            ok = false;
            break;
        }
    }
    std::cout << "\tTestFacultyPersonsSortingByIncAge ==> " << (ok ? "OK" : "NOK") << std::endl;
}


void TestFacultyStudentSortingByIncAvgGrade()
{
    Faculty faculty("Physics and Mathematics");

    faculty.PrepareCourse("Linear algebra");
    faculty.PrepareCourse("Newton mechanics");
    faculty.PrepareCourse("Thermo dynamics");

    faculty.RegisterStudent("John", 20);
    faculty.RegisterStudent("Mike", 21);
    faculty.RegisterStudent("Alice", 24);
    faculty.RegisterStudent("Anna", 22);

    const Course* linearalg = faculty.GetCourse("Linear algebra");
    const Course* mechanics = faculty.GetCourse("Newton mechanics");
    const Course* thermodyn = faculty.GetCourse("Thermo dynamics");


    Student* John = faculty.GetStudent("John");
    Student* Mike = faculty.GetStudent("Mike");
    Student* Alice = faculty.GetStudent("Alice");
    Student* Anna = faculty.GetStudent("Anna");

    // avg note -->  (1 + 2 + 3)/ 3 = 2
    John->AddCourse(linearalg, 1);
    John->AddCourse(mechanics, 2);
    John->AddCourse(thermodyn, 3);

    // avg note -->  (3 + 3.2 + 5)/ 3 ~ 3.73
    Mike->AddCourse(linearalg, 3);
    Mike->AddCourse(mechanics, 3.2);
    Mike->AddCourse(thermodyn, 5);

    // avg note -->  (1 + 1.2 + 1)/ 3 ~ 1.06
    Alice->AddCourse(linearalg, 1);
    Alice->AddCourse(mechanics, 1.2);
    Alice->AddCourse(thermodyn, 1);

    // avg note -->  (3 + 1.2 + 1)/ 3 ~ 1.73
    Anna->AddCourse(linearalg, 3);
    Anna->AddCourse(mechanics, 1.2);
    Anna->AddCourse(thermodyn, 1);

    std::vector<Student*> const studentsByIncAvgNote = faculty.GetAllStudentsSortedByAvgGrade();
    std::vector<Student*> const expected = { Alice, Anna, John, Mike };

    bool const ok = (expected == studentsByIncAvgNote);

    std::cout << "\tTestFacultyStudentSortingByIncAvgGrade ==> " << (ok ? "OK" : "NOK") << std::endl;
}


int main()
{
    TestStudentAverageGrade();
    TestFacultyStudentSortingByIncAge();
    TestFacultyPersonsSortingByIncAge();
    TestFacultyStudentSortingByIncAvgGrade();

    return 0;
}

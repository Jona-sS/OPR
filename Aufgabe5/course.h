#ifndef _COURSE_H_
#define _COURSE_H_

#include <string>

class Course
{
public:
    explicit Course(const std::string& title);

    const std::string& GetTitle() const;
private:
    const std::string _title;
};
#endif

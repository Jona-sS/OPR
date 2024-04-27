#include "course.h"

Course::Course(const std::string& title) : _title{title} {}

const std::string& Course::GetTitle() const
{
    return _title;
}

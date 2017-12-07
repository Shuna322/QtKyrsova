#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

class student : protected person
{
    bool type_of_education;  //free\paid

public:
    student();
};

#endif // STUDENT_H

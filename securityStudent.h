//
// Created by Jakob Bishop on 2019-04-01.
//

#ifndef C867_SECURITYSTUDENT_H
#define C867_SECURITYSTUDENT_H

#include "student.h"

class SecurityStudent : public Student {

public:
    using Student::Student;
    Degree getDegreeProgram() override;

private:
    Degree degreeProgram = SECURITY;

};

#endif //C867_SECURITYSTUDENT_H
//
// Created by Jakob Bishop on 2019-04-01.
//

#ifndef C867_SOFTWARESTUDENT_H
#define C867_SOFTWARESTUDENT_H

#include "student.h"

class SoftwareStudent : public Student {

public:
    using Student::Student;
    Degree getDegreeProgram() override;

private:
    Degree degreeProgram = SOFTWARE;

};

#endif //C867_SOFTWARESTUDENT_H
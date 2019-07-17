//
// Created by Jakob Bishop on 2019-04-01.
//

#ifndef C867_NETWORKSTUDENT_H
#define C867_NETWORKSTUDENT_H

#include "student.h"

class NetworkStudent : public Student {

public:
    using Student::Student;
    Degree getDegreeProgram() override;


private:
    Degree degreeProgram = NETWORKING;

};

#endif //C867_NETWORKSTUDENT_H
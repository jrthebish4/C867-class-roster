//
// Created by Jakob Bishop on 2019-04-01.
//

#ifndef C867_ROSTER_H
#define C867_ROSTER_H

#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

class Roster {

public:

    Student *classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

    void add(const string &, const string &, const string &, const string &, int, int, int, int, Degree);

    void remove(const string &);

    void printAll();

    void printDaysInCourse(const string &);

    void printInvalidEmails();

    void printByDegreeProgram(Degree);

    ~Roster();
};

#endif //C867_ROSTER_H

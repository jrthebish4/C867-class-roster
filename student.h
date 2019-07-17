//
// Created by Jakob Bishop on 2019-04-01.
//

#ifndef C867_STUDENT_H
#define C867_STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

class Student {

public:
    Student(string, string, string, string, int, Degree, int[3]);

    ~Student();

    string getStudentID();

    string getFirstName();

    string getLastName();

    string getEmailAddress();

    int getAge();

    int *getDaysToComplete();

    virtual Degree getDegreeProgram();

    void setStudentID(string);

    void setFirstName(string);

    void setLastName(string);

    void setEmailAddress(string);

    void setAge(int);

    void setDegree(Degree);

    void setDaysToComplete(const int[]);

    virtual void print();

private:
    string studentID, firstName, lastName, emailAddress;
    int age;
    Degree degree;
    int daysToComplete[3];

};

#endif //C867_STUDENT_H

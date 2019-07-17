//
// Created by Jakob Bishop on 2019-04-01.
//

#include <utility>
#include <iostream>
#include "student.h"

Student::Student(string studentId, string firstName, string lastName, string emailAddress,
                 int age, Degree degreeType, int daysToComplete[3]) {
    setStudentID(std::move(studentId));
    setFirstName(std::move(firstName));
    setLastName(std::move(lastName));
    setEmailAddress(std::move(emailAddress));
    setAge(age);
    setDegree(degreeType);
    setDaysToComplete(daysToComplete);
}

Student::~Student() = default;

void Student::setStudentID(string id) {
    studentID = std::move(id);
}

void Student::setFirstName(string fName) {
    firstName = std::move(fName);
}

void Student::setLastName(string lName) {
    lastName = std::move(lName);
}

void Student::setEmailAddress(string email) {
    emailAddress = std::move(email);
}

void Student::setAge(int studentAge) {
    age = studentAge;
}

void Student::setDegree(Degree degreeType) {
    degree = degreeType;
}

void Student::setDaysToComplete(const int *days) {
    for (int x = 0; x < 3; x++) {
        daysToComplete[x] = days[x];
    }
}

string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

int *Student::getDaysToComplete() {
    return daysToComplete;
}

void Student::print() {
    cout << "   ---" << endl;

    cout << "   Student ID: " << getStudentID() << endl;
    cout << "   First Name: " << getFirstName() << endl;
    cout << "   Last Name: " << getLastName() << endl;
    cout << "   Email: " << getEmailAddress() << endl;
    cout << "   Age: " << getAge() << endl;

    cout << "   Days to complete:";
    for (int x : daysToComplete) cout << " " << x << ",";
    cout << '\b' << " " << endl;

    switch (getDegreeProgram()) {
        case SECURITY:
            cout << "   Degree Program: Security" << endl;
            break;
        case SOFTWARE:
            cout << "   Degree Program: Software" << endl;
            break;
        case NETWORKING:
            cout << "   Degree Program: Networking" << endl;
            break;
        default:
            cout << "   Degree Program: Not Found" << endl;
            break;
    }

    cout << "   ---" << endl;
}

Degree Student::getDegreeProgram() { return DEFAULT; }

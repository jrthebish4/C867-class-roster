//
// Created by Jakob Bishop on 2019-04-01.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "roster.h"

using namespace std;

const string studentData[] =
        {
                "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                "A5,Jake,Bishop,jaketest@wgu.edu,24,10,20,30,SOFTWARE",
        };

void Roster::add(const string &studentID, const string &firstName, const string &lastName,
                 const string &emailAddress, int age, int daysInCourse1, int daysInCourse2,
                 int daysInCourse3, Degree degree) {

    int daysinCourse[3];
    daysinCourse[0] = daysInCourse1;
    daysinCourse[1] = daysInCourse2;
    daysinCourse[2] = daysInCourse3;

    for (int i = 0; i < sizeof(classRosterArray); i++) {
        if (classRosterArray[i] == nullptr) {
            switch (degree) {
                case SOFTWARE :
                    classRosterArray[i] =
                            new SoftwareStudent(studentID, firstName, lastName, emailAddress, age,
                                                degree, daysinCourse);
                    break;
                case SECURITY :
                    classRosterArray[i] =
                            new SecurityStudent(studentID, firstName, lastName, emailAddress, age,
                                                degree, daysinCourse);
                    break;
                case NETWORKING :
                    classRosterArray[i] =
                            new NetworkStudent(studentID, firstName, lastName, emailAddress, age,
                                               degree, daysinCourse);
                    break;
                default:
                    classRosterArray[i] =
                            new Student(studentID, firstName, lastName, emailAddress, age,
                                        degree, daysinCourse);
                    break;
            }
            break;
        }
    }
}

void Roster::remove(const string &studentID) {
    cout << endl << "Updating Roster..." << endl;

    bool success = false;
    for (auto &i : classRosterArray) {
        if (i != nullptr) {
            if (i->getStudentID() == studentID) {
                i = nullptr;
                success = true;
                break;
            }
        }
    }

    if (success) {
        cout << "Student " << studentID <<
             " was successfully dropped from the roster." << endl;
    } else {
        cout << "Student " << studentID <<
             " was not found on the roster." << endl;
    }
}

void Roster::printAll() {
    for (const auto &i : classRosterArray) {
        i->print();
    }
}

void Roster::printDaysInCourse(const string &studentID) {
    for (const auto &i : classRosterArray) {
        if (i->getStudentID() == studentID) {
            int *days = i->getDaysToComplete();
            int average = (days[0] + days[1] + days[2]) / 3;
            cout << "   - Student " << studentID <<
                 " average: " << average
                 << " days" << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (const auto &i : classRosterArray) {
        string email = i->getEmailAddress();
        if (email.find('@') == string::npos) {
            cout << "  - " << email << endl;
        } else if (email.find('.') == string::npos) {
            cout << "  - " << email << endl;
        } else if (email.find(' ') != string::npos) {
            cout << "  - " << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
    for (const auto &i : classRosterArray) {
        if (degreeProgram == i->getDegreeProgram()) {
            i->print();
        }
    }
}

int main() {
    Roster classRoster;

    cout << endl << "C867 - Scripting and Programming: C++" << endl;
    cout << "Jakob Bishop - WGU" << endl;

    for (const auto &i : studentData) {
        vector<string> student;
        stringstream stringStream(i);

        while (stringStream.good()) {
            string substring;
            getline(stringStream, substring, ',');
            student.push_back(substring);
        }

        if (find(student.begin(), student.end(), "SECURITY") != student.end()) {
            classRoster.add(student[0], student[1], student[2], student[3], stoi(student[4]),
                            stoi(student[5]), stoi(student[6]), stoi(student[7]), SECURITY);
        } else if (find(student.begin(), student.end(), "SOFTWARE") != student.end()) {
            classRoster.add(student[0], student[1], student[2], student[3], stoi(student[4]),
                            stoi(student[5]), stoi(student[6]), stoi(student[7]), SOFTWARE);
        } else if (find(student.begin(), student.end(), "NETWORK") != student.end()) {
            classRoster.add(student[0], student[1], student[2], student[3], stoi(student[4]),
                            stoi(student[5]), stoi(student[6]), stoi(student[7]), NETWORKING);
        }
    }

    cout << endl << "Class Roster:" << endl;
    classRoster.printAll();

    cout << endl << "Invalid Emails:" << endl;
    classRoster.printInvalidEmails();

    cout << endl << "Average Number of Days per Course:" << endl;
    for (const auto &i : classRoster.classRosterArray) {
        classRoster.printDaysInCourse(i->getStudentID());
    }

    cout << endl << "Software Degree Students:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");
    classRoster.remove("A3");

    classRoster.~Roster();

    return 0;
}


Roster::~Roster() = default;

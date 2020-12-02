/*
    ARYAN J. PATIL
    BT18CSE096
*/


#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include "Address.h"
#include "Person.h"

using namespace std;

enum Designation{HOD, Professor, AssistantProfessor, AssociateProfessor, TeachingAssistant};

class Faculty : public Person
{
private:
    const int F_ID;
    Designation desig;
    int numCourses;
    string* courses;
public:
    Faculty(string, Department, Designation, string, string, string);

    int getId();
    int getNumCourses();
    bool getCourses(string);

    bool addCourses(string);
    bool removeCourses(string);

    void print();
    
    ~Faculty();
};

#endif
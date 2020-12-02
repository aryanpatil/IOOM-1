#ifndef STUDENT_H
#define STUDENT_H

#include <string>
/*
    ARYAN J. PATIL
    BT18CSE096
*/


#include "Address.h"
#include "Person.h"

using namespace std;

class Student : public Person
{
private:
    const int STUD_ID ;
    int numCourses;
    string* courses;
    int* grade;
public:
    Student(string, Department, string, string, string);

    int getNumCourses();
    double getAvgGrade();

    bool addCourse(string);
    bool addCoursesGrade(string, int);
    bool dropCourse(string);
    void printGrade();
    
    void print();

    ~Student();

private:
    int getId();

};

#endif
/*
    ARYAN J. PATIL
    BT18CSE096
*/


#include <iostream>
#include <string>
#include "Address.h"
#include "Person.h"
#include "Student.h"

using namespace std;

Student::Student(string Name, Department Dept, string house, string street, string city) :
Person(Name, Dept, house, street, city),STUD_ID(getID()), numCourses(0)
{
    this->courses = new string[getMax()];
    this->grade = new int[getMax()];
}

int Student::getNumCourses()
{
    return this->numCourses;
}

int Student::getId()
{
    return this->STUD_ID;
}

double Student::getAvgGrade()
{
    double avgGrade = 0.0;

    for (int i = 0; i < this->numCourses; i++)
    {
        avgGrade += this->grade[i];
    }
    if(this->numCourses>0)
    {
        avgGrade = avgGrade / this->numCourses;
    }
    return avgGrade;
}

bool Student::addCourse(string courseName)
{
    if (this->numCourses < this->getMax())
    {
        for (int i = 0; i < this->numCourses; i++)
        {
            if (this->courses[i] == courseName)
            {
                return false;
            }
        }

        this->courses[numCourses] = courseName;
        this->grade[numCourses] = 0;
        this->numCourses++;
    }
    else
    {
        return false;
    }

    return true;
}

bool Student::addCoursesGrade(string courseName, int marks)
{
    for (int i = 0; i < this->numCourses; i++)
    {
        if (this->courses[i] == courseName)
        {
            this->grade[i] = marks;
            return true;
        }
    }
    return false;
}

bool Student::dropCourse(string courseName)
{
    for (int i = 0; i < this->numCourses; i++)
    {
        if (this->courses[i] == courseName)
        {
            for (int j = i + 1; j < this->numCourses; j++)
            {
                this->courses[j - 1] = this->courses[j];
                this->grade[j - 1] = this->grade[j];
            }
            this->numCourses--;

            return true;
        }
    }
    return false;
}

void Student::printGrade()
{
    cout << "Course\tGrade\n";
    for (int i = 0; i < this->numCourses; i++)
    {
        cout << (i+1) << ". " << this->courses[i] << "\t" << this->grade[i] << "\n";
    }
    cout << "Average Grade : " << this->getAvgGrade() << "\n";
}

void Student::print()
{
    cout << "class : Student\n";
    cout << "Id : " << this->getId() << "\n";
    cout << "Name : " << this->getName() << "\n";
    cout << "Department : " << this->getDept() << "\n";
    this->printAddress();
    cout << "Number of courses : " << this->getNumCourses() << "\n";
    this->printGrade();
    cout << "----------------------------------------------------------------------------------\n";

}

Student::~Student()
{
    delete[] this->courses;
    delete[] this->grade;
}
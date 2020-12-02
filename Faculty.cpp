/*
    ARYAN J. PATIL
    BT18CSE096
*/


#include <iostream>
#include <string>
#include "Address.h"
#include "Person.h"
#include "Faculty.h"

using namespace std;

Faculty::Faculty(string Name, Department Dept, Designation Desig, string house, string street, string city):
Person(Name, Dept, house, street, city),F_ID(getID()), numCourses(0), desig(Desig)
{

    this->courses = new string[getMax()];
}

int Faculty::getId()
{
    return this->F_ID;
}

int Faculty::getNumCourses()
{
    return this->numCourses;
}

bool Faculty::getCourses(string subject)
{
    for(int i=0;i<this->numCourses;i++)
    {
        if(this->courses[i]==subject)
        {
            return true;
        }
    }

    return false;
}

bool Faculty::addCourses(string courseName)
{
    if(this->numCourses < getMax())
    {
        for(int i=0;i<this->numCourses;i++)
        {
            if(this->courses[i]==courseName)
            {
                return false;
            }
        }

        this->courses[this->numCourses] = courseName;
        this->numCourses++;
    }
    else
    {
        return false;
    }
    
    return true;
}

bool Faculty::removeCourses(string courseName)
{
    for(int i=0;i<this->numCourses;i++)
    {
        if(this->courses[i]==courseName)
        {
            for(int j=i+1;j<this->numCourses;j++)
            {
                this->courses[j-1] = this->courses[j];
            }
            this->numCourses--; 

            return true;
        }
    }
    return false;
}

void Faculty::print()
{
    cout << "class : Faculty\n";
    cout << "Id : " << this->getId() << "\n";
    cout << "Name : " << this->getName() << "\n";
    cout << "Department : " << this->getDept() << "\n";
    this->printAddress();
    cout << "Number of courses : " << this->getNumCourses() << "\n";
    cout << "Course Name :" << "\n";
    for(int i=0;i<this->getNumCourses();i++)
    {
        cout << (i+1) << ". " << this->courses[i] << "\n";
    }
    cout << "----------------------------------------------------------------------------------\n";

}

Faculty::~Faculty()
{
    delete[] this->courses;
}
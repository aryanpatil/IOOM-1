/*
    ARYAN J. PATIL
    BT18CSE096
*/


#include <iostream>
#include <string>
#include "Address.h"
#include "Person.h"

using namespace std;

Person::Person(string Name, Department Dept, string house, string street, string city):
address(house, street, city), name(Name), dept(Dept), MAX(6), id(count+1)
{
    this->count++;
}

string Person::getName()
{
    return this->name;
}

Department Person::getDept()
{
    return this->dept;
}

const int Person::getMax()
{
    return this->MAX;
}

const int Person::getIdee()
{
    return this->id;
}

void Person::printAddress()
{
    cout << "Address : " << this->address.getHouse_num() << ", " << this->address.getStreet_name() << ", " << this->address.getCity_name() << "\n"; 
}

void Person::setName(string Name)
{
    this->name = Name;
}

void Person::setDept(Department Dept)
{
    this->dept = Dept;
}

void Person::changeName(string Name)
{
    this->name = Name;
}

void Person::changeAddress(string house, string street, string city)
{
    this->address.setAddress(house, street, city);
}

int Person::getID()
{
    return count;
}

// Print details of Person
void Person::print()
{
    cout << "class : Person\n";
    cout << "Id : " << this->getIdee() << "\n";
    cout << "Name : " << this->getName() << "\n";
    cout << "Department : " << this->getDept() << "\n";
    this->printAddress();
    cout << "----------------------------------------------------------------------------------\n";
}

Person::~Person(){}
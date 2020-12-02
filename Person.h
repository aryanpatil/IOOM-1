/*
    ARYAN J. PATIL
    BT18CSE096
*/


#ifndef PERSON_H
#define PERSON_H

#include "Address.h"
#include <string>
using namespace std;

// Department enumeration
enum Department{CSE, ECE, EEE, CHE, MME, MEC};

class Person
{
    static int count;
private:
    const int id;
    string name;
    Address address;
    const int MAX;
    Department dept;
public:
    Person(string, Department, string, string, string);

    string getName();
    Department getDept();
    const int getMax();
    const int getIdee();
    void printAddress();

    void setName(string);
    void setDept(Department);
    void changeName(string);
    void changeAddress(string, string, string);
    
    static int getID();

    virtual void print();

    ~Person();
};

#endif
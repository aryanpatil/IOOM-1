/*
    ARYAN J. PATIL
    BT18CSE096
*/


#include <iostream>
#include <string>
#include "Address.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

int Person::count = 0;

void print_all(Person* p)
{
    p->print();
}

int main()
{ 
    // INTERFACE

    int exit=0, input=0, deptNo=0, marks;
    string name, house, street, city, course;
    Department dept;
    Designation desig;

    while(!exit)
    {
        std::cout << "Press\n1.Create a profile\n2.Exit\n";
        cin >> input;

        if(input==1)
        {   
            // Input Name
            std::cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            // Input Department
            std::cout << "Enter Department Number (Options: 0.CSE, 1.ECE, 2.EEE, 3.CHE, 4.MME, 5.MEC) : ";
            cin >> deptNo;
            dept = (Department)deptNo;
            
            // Input Address Details
            std::cout << "Enter Address details:\nHouse Number: ";
            cin.ignore();
            getline(cin, house);
            std::cout << "Street Name: ";
            //cin.ignore();
            getline(cin, street);
            std::cout << "City Name: ";
            //cin.ignore();
            getline(cin, city);

            // Choose the position
            std::cout << "Choose position: 1.Faculty\t2.Student\n";
            cin >> input;

            if(input == 1)
            {   // Choose the designation
                std::cout << "Enter Designation Number: (Options: 0.HOD, 1.Professor, 2.AssistantProfessor, 3.AssociateProfessor, 4.TeachingAssistant) : ";
                cin >> input ;
                desig = (Designation)input;

                // Create faculty object
                Faculty* facul = new Faculty(name, dept, desig, house, street, city);

                // add or remove courses
                input=1; 
                while(input!=0)
                {
                    std::cout << "1. Add a course\n2. Delete a course\n0. Exit\n";
                    std::cin >> input;
                    if(input==1)
                    {
                        std::cout << "Enter the course to be added (No spaces): ";
                        cin >> course;
                        if(facul->addCourses(course))
                        {
                            cout << "Course successfully added!\n";
                        }
                        else
                        {
                            cout << "Failed! Max Value reached or course already present\n";
                        }
                        
                    }
                    else if(input==2)
                    {
                        std::cout << "Enter the course to be removed (No spaces): ";
                        cin >> course;
                        if(facul->getCourses(course))
                        {
                            facul->removeCourses(course);
                            cout << "Course successfully removed!\n";
                        }
                        else
                        {
                            cout << "Failed! No such course present.\n";
                        }
                    }
                    
                }
                // Details of faculty
                print_all(facul);
            }
            else if(input==2)
            {
                // Create student object
                Student* stud = new Student(name, dept, house, street, city);

                // add or remove courses and grades
                input=1; 
                while(input!=0)
                {
                    std::cout << "1. Add a course and its grade\n2. Delete a course\n3. Print grades\n0. Exit\n";
                    std::cin >> input;
                    if(input==1)
                    {
                        std::cout << "Enter the course to be added (No spaces): ";
                        cin >> course;
                        if(stud->addCourse(course))
                        {
                            std::cout << "Enter the grades (Out of 100): ";
                            cin >> marks;
                            stud->addCoursesGrade(course, marks);
                            std::cout << "Course and its grade successfully added!\n";
                        }
                        else
                        {
                            cout << "Failed! Max Value reached or course already present\n";
                        }
                        
                    }
                    else if(input==2)
                    {
                        std::cout << "Enter the course to be removed (No spaces): ";
                        cin >> course;
                        if(stud->dropCourse(course))
                        {
                            cout << "Course successfully removed!\n";
                        }
                        else
                        {
                            cout << "Failed! No such course present.\n";
                        }
                    }
                    else if(input==3)
                    {
                        stud->printGrade();
                    }
                    
                }
                // Details of student
                print_all(stud);
            }
            else{
                std::cout << "Invalid Input!\n";
            }

        }
        else if (input==2)
        {
            exit = 1;
        }
        else
        {
            cout << "Invalid Input!\n";
        }
        
    }
    
    
    
    
    
  /*--------------------------------------------------------------------------------------------------------------------------*/  
    // HARD-CODED DEMONSTRATION
    
    cout << "HARD-CODED DEMONSTRATION\n\n";
    cout << "--------------------------------------------------------------------------------\n";
    
    // Demonstration for Person class
    Person* person = new Person("Alpha", CSE, "103, Gopal Tower", "Khat Road", "Bhandara");
    cout << "PERSON CLASS: \n";
    // Change of name
    cout << "Name of person: " << person->getName() << "\n";
    person->setName("Wolf");
    cout << "Changed name of person: " << person->getName() << "\n";

    // Change of department
    cout << "Department: " << person->getDept() << "\n";
    person->setDept(EEE);
    cout << "Changed Department: " << person->getDept() << "\n";

    // Change of Address
    person->printAddress();
    person->changeAddress("127", "Jawahar Nagar", "Mysore");
    cout << "Changed " ;person->printAddress(); cout<<"\n";

    // Demonstration for Student class
    Student* student = new Student("Beta", ECE, "49, Matrusmurti Nagar", "Khat Road", "Bhandara");
    cout << "STUDENT CLASS: \n";
    // Addition of Courses
    student->addCourse("DSPD"); student->addCoursesGrade("DSPD", 85);
    student->addCourse("IOOM"); student->addCoursesGrade("IOOM", 90);
    student->addCourse("NFT");  student->addCoursesGrade("NFT", 80);
    cout << "Number of courses enrolled: " << student->getNumCourses() << "\n";
    cout << "Courses along with grades:\n" ; student->printGrade();

    // Dropping of a course
    student->dropCourse("DSPD");
    cout << "Number of courses enrolled after dropping a course: " << student->getNumCourses() << "\n";
    cout << "Courses along with grades after dropping a course:\n"; student->printGrade(); cout << "\n";
    
    // Demonstration of Faculty class
    Faculty* faculty = new Faculty("Gamma", EEE, HOD, "43, Vnit Campus", "Bajaj Nagar", "Nagpur");
    cout << "FACULTY CLASS: \n";
    // Addition of Courses
    faculty->addCourses("IOOM");
    faculty->addCourses("NFT");
    faculty->addCourses("OS");
    cout << "Number of courses undertaken: " << faculty->getNumCourses() << "\n";

    // Find if a course is undertaken 
    cout << "Is IOOM undertaken? \n";
    if(faculty->getCourses("IOOM"))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    // Dropping a course
    faculty->removeCourses("IOOM");
    cout << "IOOM course dropped\n";
    cout << "Is IOOM undertaken? \n";
    if(faculty->getCourses("IOOM"))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    cout << "\n";

    // Demonstration of Dynamic Polymorphism
    cout << "DYNAMIC POLYMORPHISM:\n";
    Person* people[3];
    people[0] = person;
    people[1] = student;
    people[2] = faculty;

    print_all(people[0]);
    print_all(people[1]);
    print_all(people[2]);

    return 0;
}
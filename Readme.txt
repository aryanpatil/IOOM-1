Name        : Aryan Jotish Patil
Roll_no     : BT18CSE096

------------------------------------------------------------------------
Files Included (11):
    Address.h               Address.cpp
    Person.h                Person.cpp
    Student.h               Student.cpp
    Faculty.h               Faculty.cpp
    makefile                Readme.txt
    main.cpp
------------------------------------------------------------------------

To Run Code enter the below commands

make all
./main

OR

g++ main.cpp Address.cpp Person.cpp Student.cpp Faculty.cpp
./a.out

------------------------------------------------------------------------
The code is well commented and almost all the functions are self explanatory.
------------------------------------------------------------------------

The Person class has "HAS A" relation with Address class.
Student and Faculty classes are inherited from Person class.
So, Student and Faculty classes have "IS A" relation with Person class.
------------------------------------------------------------------------

The Main function prompts for an input at the start:
1. Create your own profile
2. Exit to see the hard-coded demonstration of all functions as well as Dynamic polymorphism

1. Creating own profile:
    a. The program asks user for name, department(enum) and address to enter.
    b. The program then asks user to select the profile :
        1. Faculty
        2. Student
    
    c1. Faculty: 
        i. The program asks user to enter the designation(enum)
        ii. The programs goes into a loop where it asks user to 
            1. Add a course[Max allowed courses = 6]
            2. Remove a course
            3. Exit
        iii. The program prints the details of faculty object created.

    c2. Student:
        ii. The programs goes into a loop where it asks user to 
            1. Add a course and its grade(out of 100)[Max allowed courses = 6]
            2. Remove/Drop a course
            3. Print courses and their grades
            4. Exit
        iii. The program prints the details of student object created.

2. Hard-coded demonstration of all functions and Dynamic Polymorphism:
    The main function creates objects of Person, Student, Faculty classes
    respectively and various functions along with suitable print statements
    are shown.  
    The Output of the program is self-explainatory as it tells us what it is
    Doing. And Hence no need of giving any input.

------------------------------------------------------------------------

The Output of The Hard-Code Looks like : (The output is self-explainatory)

    HARD-CODED DEMONSTRATION

    --------------------------------------------------------------------------------
    PERSON CLASS: 
    Name of person: Alpha
    Changed name of person: Wolf
    Department: 0
    Changed Department: 2
    Address : 103, Gopal Tower, Khat Road, Bhandara
    Changed Address : 127, Jawahar Nagar, Mysore

    STUDENT CLASS: 
    Number of courses enrolled: 3
    Courses along with grades:
    Course  Grade
    1. DSPD 85
    2. IOOM 90
    3. NFT  80
    Average Grade : 85
    Number of courses enrolled after dropping a course: 2
    Courses along with grades after dropping a course:
    Course  Grade
    1. IOOM 90
    2. NFT  80
    Average Grade : 85

    FACULTY CLASS: 
    Number of courses undertaken: 3
    Is IOOM undertaken? 
    YES
    IOOM course dropped
    Is IOOM undertaken? 
    NO

    DYNAMIC POLYMORPHISM:
    class : Person
    Id : 1
    Name : Wolf
    Department : 2
    Address : 127, Jawahar Nagar, Mysore
    ----------------------------------------------------------------------------------
    class : Student
    Id : 2
    Name : Beta
    Department : 1
    Address : 49, Matrusmurti Nagar, Khat Road, Bhandara
    Number of courses : 2
    Course  Grade
    1. IOOM 90
    2. NFT  80
    Average Grade : 85
    ----------------------------------------------------------------------------------
    class : Faculty
    Id : 3
    Name : Gamma
    Department : 2
    Address : 43, Vnit Campus, Bajaj Nagar, Nagpur
    Number of courses : 2
    Course Name :
    1. NFT
    2. OS
    ----------------------------------------------------------------------------------

------------------------------------------------------------------------

Department And Designations are Enums and hence output is displayed in
numbers since they get mapped to numbers from 0 to n-1.

------------------------------------------------------------------------

Thank You.

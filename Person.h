// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: helper.h
// NCC CSCE 306 1 - OO Software Development
// Lab 9 - Two-File Style Class
// Description: This file contains the Peroosn class declaration
// --------------------------------------------------------------------------------------

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructors
    Person();
    Person(std::string name, int age);

    // Destructor
    ~Person();

    // Getter and setter methods
    std::string getName() const;
    void setName(const std::string& name);
    int getAge() const;
    void setAge(int age);

    // Other methods
    void display() const;
};

#endif // PERSON_H

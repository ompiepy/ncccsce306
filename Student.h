// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: helper.h
// NCC CSCE 306 1 - OO Software Development
// Lab 10 - Object Inheritance Single Parent
// Description: This file contains the Student class declaration
// --------------------------------------------------------------------------------------

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h" // Include the Person class header file

class Student : public Person { // Student inherits from Person
private:
    std::string studentID;
    std::string major;

public:
    // Constructors
    Student();
    Student(std::string name, int age, std::string studentID, std::string major);

    // Destructor
    ~Student();

    // Getter and setter methods for studentID and major
    std::string getStudentID() const;
    void setStudentID(const std::string& studentID);
    std::string getMajor() const;
    void setMajor(const std::string& major);

    // Override the display method from the base class
    void display() const;
};

#endif // STUDENT_H

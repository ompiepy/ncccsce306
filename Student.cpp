// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: helper.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab 10 - Object Inheritance Single Parent
// Description: This file contains the definitions of Student Class.
// --------------------------------------------------------------------------------------

#include "Student.h"
#include <iostream>

// Constructors
Student::Student() : Person(), studentID(""), major("") {}

Student::Student(std::string name, int age, std::string studentID, std::string major) :
    Person(name, age), studentID(studentID), major(major) {}

// Destructor
Student::~Student() {}

// Getter and setter methods for studentID and major
std::string Student::getStudentID() const {
    return studentID;
}

void Student::setStudentID(const std::string& studentID) {
    this->studentID = studentID;
}

std::string Student::getMajor() const {
    return major;
}

void Student::setMajor(const std::string& major) {
    this->major = major;
}

// Override the display method from the base class
void Student::display() const {
    std::cout << "Name: " << getName() << ", Age: " << getAge() << ", Student ID: " << studentID << ", Major: " << major << std::endl;
}
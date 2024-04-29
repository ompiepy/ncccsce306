// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: helper.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab 10 - Object Inheritance Single Parent
// Description: This file contains the definitions of Person Class
// --------------------------------------------------------------------------------------
#include "Person.h"

// Constructors
Person::Person() : name(""), studentID(0), city(""), callName("") {}

Person::Person(std::string name, int studentID, std::string city, std::string callName) :
    name(name), studentID(studentID), city(city), callName(callName) {}

// Getter and setter methods
std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

int Person::getStudentID() const {
    return studentID;
}

void Person::setStudentID(int studentID) {
    this->studentID = studentID;
}

std::string Person::getCity() const {
    return city;
}

void Person::setCity(const std::string& city) {
    this->city = city;
}

std::string Person::getCallName() const {
    return callName;
}

void Person::setCallName(const std::string& callName) {
    this->callName = callName;
}

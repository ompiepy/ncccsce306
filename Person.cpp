// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: helper.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab 10 - Object Inheritance Single Parent
// Description: This file contains the definitions of Person Class
// --------------------------------------------------------------------------------------

#include "Person.h"
#include <iostream>

// Constructors
Person::Person() : name(""), age(0) {}

Person::Person(std::string name, int age) : name(name), age(age) {}

// Destructor
Person::~Person() {}

// Getter and setter methods
std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    this->age = age;
}

// Other methods
void Person::display() const {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}

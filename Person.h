// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: helper.h
// NCC CSCE 306 1 - OO Software Development
// Lab 10 - Object Inheritance Single Parent
// Description: This file contains the Peroosn class declaration
// --------------------------------------------------------------------------------------
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    int studentID;
    std::string city;
    std::string callName;

public:
    // Constructors
    Person();
    Person(std::string name, int studentID, std::string city, std::string callName);

    // Getter and setter methods
    std::string getName() const;
    void setName(const std::string& name);
    int getStudentID() const;
    void setStudentID(int studentID);
    std::string getCity() const;
    void setCity(const std::string& city);
    std::string getCallName() const;
    void setCallName(const std::string& callName);
};

#endif // PERSON_H

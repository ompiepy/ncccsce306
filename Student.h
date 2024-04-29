// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: helper.h
// NCC CSCE 306 1 - OO Software Development
// Lab 10 - Object Inheritance Single Parent
// Description: This file contains the Student class declaration
// --------------------------------------------------------------------------------------
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
#include <vector>
#include <unordered_map>

class Student : public Person {
private:
    float gpa;
    std::string degree;

public:
    // Constructors
    Student();
    Student(std::string name, int studentID, float gpa, std::string degree, std::string city, std::string callName);

    // Getter and setter methods
    float getGPA() const;
    void setGPA(float gpa);
    std::string getDegree() const;
    void setDegree(const std::string& degree);

    // Additional computations
    static float computeAverageGPA(const std::vector<Student>& students);
    static std::unordered_map<std::string, float> computeGPAPerDegree(const std::vector<Student>& students);
    static float highestGPA(const std::vector<Student>& students);
    static std::string mostPursuedDegreeType(const std::vector<Student>& students);
    static void sortStudents(std::vector<Student>& students);
    static std::string cityWithHighestAverageGPA(const std::vector<Student>& students);

    // Display method
    void display() const;
};

#endif // STUDENT_H

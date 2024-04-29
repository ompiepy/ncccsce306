// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: helper.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab 10 - Object Inheritance Single Parent
// Description: This file contains the definitions of Student Class.
// --------------------------------------------------------------------------------------
#include "Student.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

// Constructors
Student::Student() : Person(), gpa(0.0), degree("") {}

Student::Student(std::string name, int studentID, float gpa, std::string degree, std::string city, std::string callName) :
    Person(name, studentID, city, callName), gpa(gpa), degree(degree) {}

// Getter and setter methods
float Student::getGPA() const {
    return gpa;
}

void Student::setGPA(float gpa) {
    this->gpa = gpa;
}

std::string Student::getDegree() const {
    return degree;
}

void Student::setDegree(const std::string& degree) {
    this->degree = degree;
}

// Additional computations
float Student::computeAverageGPA(const std::vector<Student>& students) {
    float totalGPA = 0.0;
    for (const auto& student : students) {
        totalGPA += student.getGPA();
    }
    return totalGPA / students.size();
}

// Compute GPA for each degree type: UG, G, PG, and D.
std::unordered_map<std::string, float> Student::computeGPAPerDegree(const std::vector<Student>& students) {
    std::unordered_map<std::string, float> averageGPAPerDegree;
    std::unordered_map<std::string, int> degreeCount;

    for (const auto& student : students) {
        degreeCount[student.getDegree()]++;
        averageGPAPerDegree[student.getDegree()] += student.getGPA();
    }

    for (auto& entry : averageGPAPerDegree) {
        entry.second /= degreeCount[entry.first];
    }

    return averageGPAPerDegree;
}

// Determine the highest GPA (including ties).
float Student::highestGPA(const std::vector<Student>& students) {
    float maxGPA = 0.0;
    for (const auto& student : students) {
        maxGPA = std::max(maxGPA, student.getGPA());
    }
    return maxGPA;
}

// Compute the most pursued Degree Type.
std::string Student::mostPursuedDegreeType(const std::vector<Student>& students) {
    std::unordered_map<std::string, int> degreeCount;
    for (const auto& student : students) {
        degreeCount[student.getDegree()]++;
    }

    int maxCount = 0;
    std::string mostPursuedDegree;
    for (const auto& entry : degreeCount) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostPursuedDegree = entry.first;
        }
    }

    return mostPursuedDegree;
}

// Sort each degree type (first by degree) and within each degree by GPA.
bool compareStudents(const Student& a, const Student& b) {
    if (a.getDegree() != b.getDegree()) {
        return a.getDegree() < b.getDegree();
    }
    return a.getGPA() > b.getGPA();
}

void Student::sortStudents(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), compareStudents);
}

// Extra Credit: Compute the City with the highest Average GPA.
std::string Student::cityWithHighestAverageGPA(const std::vector<Student>& students) {
    std::unordered_map<std::string, std::pair<float, int>> cityGPAInfo;

    for (const auto& student : students) {
        cityGPAInfo[student.getCity()].first += student.getGPA();
        cityGPAInfo[student.getCity()].second++;
    }

    float maxAverageGPA = 0.0;
    std::string cityWithHighestGPA;
    for (const auto& entry : cityGPAInfo) {
        float averageGPA = entry.second.first / entry.second.second;
        if (averageGPA > maxAverageGPA) {
            maxAverageGPA = averageGPA;
            cityWithHighestGPA = entry.first;
        }
    }

    return cityWithHighestGPA;
}

// Display method
void Student::display() const {
    //std::cout << getName() << "\t\t" << getStudentID() << "\t" << getGPA() << "\t\t" << getDegree() << "\t" << getCity() << "\t\t" << getCallName() << std::endl;
    std::printf("%-10s%-10d%-10.2f%-15s%-10s%-10s\n", getName().c_str(), getStudentID(), getGPA(), getDegree().c_str(), getCity().c_str(), getCallName().c_str());
}
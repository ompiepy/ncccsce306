// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: main.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab #11- Object Collection Management
// Description: This lab focuses on object inheritance with a single parent class
// --------------------------------------------------------------------------------------
#include "Student.h"
#include <iostream>
#include <vector>

int main() {
    // Create a vector to store Student objects
    std::vector<Student> students;

    // Populate the vector with Student objects
    students.push_back(Student("Adam", 100001, 3.4, "Undergraduate", "Raleigh", "Rousseau"));
    students.push_back(Student("Alice", 100010, 3.7, "Undergraduate", "Raleigh", "Riagan"));
    students.push_back(Student("Andy", 100011, 3.9, "Post-Graduate", "Raleigh", "Rasputin"));
    students.push_back(Student("Adrian", 100100, 3.6, "Post-Graduate", "Raleigh", "Radcliff"));
    students.push_back(Student("Arron", 100101, 3.4, "Undergraduate", "Raleigh", "Romanoff"));
    students.push_back(Student("Aries", 100110, 3.8, "Undergraduate", "Raleigh", "Ramsey"));
    students.push_back(Student("Ashton", 100111, 3.8, "Doctoral", "Raleigh", "Rey"));
    students.push_back(Student("Aquafina", 101000, 3.8, "Undergraduate", "Reno", "Ricci"));
    students.push_back(Student("Ann", 101001, 3.6, "Undergraduate", "Reno", "Rice"));
    students.push_back(Student("Antwan", 101010, 3.8, "Undergraduate", "Reno", "Rose"));
    students.push_back(Student("Abe", 101011, 4.0, "Graduate", "Reno", "Ryan"));
    students.push_back(Student("Ashley", 101100, 3.5, "Graduate", "Reno", "Robertson"));
    students.push_back(Student("Aliah", 101100, 3.8, "Graduate", "Richmond", "Reynolds"));
    students.push_back(Student("Apo", 101101, 3.7, "Doctoral", "Richmond", "Russell"));
    students.push_back(Student("Alana", 101110, 3.8, "Undergraduate", "Richmond", "Ross"));
    students.push_back(Student("Alex", 101111, 3.8, "Post-Graduate", "Rochester", "Richardson"));
    students.push_back(Student("Allie", 110000, 4.0, "Post-Graduate", "Rochester", "Rogers"));
    students.push_back(Student("Artie", 110001, 3.8, "Undergraduate", "Rochester", "Reed"));
    students.push_back(Student("Atemus", 110010, 4.0, "Doctoral", "Richmond", "Roberts"));
    students.push_back(Student("Ariana", 110011, 3.3, "Graduate", "Richmond", "Robinson"));

    // Perform computations and display results

    // Compute GPA for each degree type: UG, G, PG, and D.
    std::unordered_map<std::string, float> averageGPAPerDegree = Student::computeGPAPerDegree(students);
    std::cout << "Average GPA per degree type:" << std::endl;
    for (const auto& entry : averageGPAPerDegree) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    // Determine the highest GPA (including ties).
    float maxGPA = Student::highestGPA(students);
    std::cout << "Highest GPA: " << maxGPA << std::endl;

    // Compute the most pursued Degree Type.
    std::string mostPursuedDegree = Student::mostPursuedDegreeType(students);
    std::cout << "Most pursued degree type: " << mostPursuedDegree << std::endl;

    // Sort each degree type (first by degree) and within each degree by GPA.
    Student::sortStudents(students);

    // Display sorted students
    std::cout << "\nSorted students:" << std::endl;
    std::printf("%-10s%-10s%-10s%-15s%-10s%-10s\n", "Name", "Student ID", "GPA", "Degree", "City", "Call Name");
    for (const auto& student : students) {
        student.display();
    }

    // Extra Credit: Compute the City with the highest Average GPA.
    std::string cityWithHighestGPA = Student::cityWithHighestAverageGPA(students);
    std::cout << "\nCity with highest average GPA: " << cityWithHighestGPA << std::endl;

    return 0;
}

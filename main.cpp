// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: main.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab 10 - Object Inheritance Single Parent
// Description: This lab focuses on object inheritance with a single parent class
// --------------------------------------------------------------------------------------

#include "Person.h"
#include "Student.h"
#include <vector>

int main() {
    // Create objects of both Person and Student classes
    Person person("Alice", 30);
    Student student("Bob", 25, "S12345", "Computer Science");

    // Call methods on objects
    person.display();
    student.display();

    // Test inherited methods
    student.setName("Charlie");
    student.setAge(40);
    student.setStudentID("S67890");
    student.setMajor("Electrical Engineering");
    student.display();

    return 0;
}

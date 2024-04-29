// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: main.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab 9 - Two-File Style Class
// Description: This lab focuses on creating a class that is split 
// into two files: a header file and a source file.
// --------------------------------------------------------------------------------------

#include "Person.h"
#include <vector>

int main() {
    // Instantiate several Person objects
    Person person1("Alice", 30);
    Person person2("Bob", 25);

    // Call methods on individual objects
    person1.display();
    person2.display();

    // Create a vector of Person objects
    std::vector<Person> people;
    people.push_back(Person("Charlie", 40));
    people.push_back(Person("Diana", 35));

    // Call methods on objects in the vector
    for (const auto& person : people) {
        person.display();
    }

    return 0;
}

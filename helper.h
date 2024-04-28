// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: helper.h
// NCC CSCE 306 1 - OO Software Development
// Lab 8: Passing Values, References, and Pointers to Functions
// Description: This file contains the helper function declarations that will be used in the helper.cpp file.
// --------------------------------------------------------------------------------------

#include <iostream> // Standard Input/Output Library
#include <string> // Standard String Library
# include <array> // Standard Array Library

#ifndef HELPER_H
#define HELPER_H

// Add your helper function declarations here
// Add the declarations of all the functions defined in the helper.cpp
// Function to accept an integer variable
void take_simple_variable(int my_integer);

// Function to accept a double variable
void take_simple_variable(double my_double);

// Function to accept a string variable
void take_simple_variable(std::string ten_ten);

// Function to accept an integer array
void take_simple_variable(int int_array_five[]);

// Function to accept a standard integer array
template <size_t N>
void take_simple_variable(std::array<int, N>& std_int_array) {
    for (int i = 0; i < N; i++) {
        std::cout << "std_int_array["<<i<<"]: " << std_int_array[i] << " memory reference: " << &std_int_array[i] << std::endl;
    }
}

// Function to accept a reference variable for an integer
void take_reference_variable(int my_int_ref);

// Function to accept a reference variable for a double
void take_reference_variable(double my_dbl_ref);

// Function to accept a reference variable for a string
void take_reference_variable(std::string my_str_ref);

// Function to accept a reference variable for an integer array
void take_reference_variable(int my_array_ref[]);

// Function to accept a reference variable for a standard integer array
template <size_t N>
void take_reference_variable(std::array<int, N>& std_array_ref) {
    for (int i = 0; i < N; i++) {
        std::cout << "std_array_ref["<<i<<"]: " << std_array_ref[i] << " memory reference: " << &std_array_ref[i] << " de-referenced value: " << std_array_ref[i] << std::endl;
    }
}

// Function to accept a pointer variable for an integer
void take_pointer_variable(int my_int_ptr);

// Function to accept a pointer variable for a double
void take_pointer_variable(double my_dbl_ptr);

// Function to accept a pointer variable for a string
void take_pointer_variable(std::string my_str_ptr);

// Function to accept a pointer variable for an integer array
void take_pointer_variable(int my_array_ptr[]);

// Function to accept a pointer variable for a standard integer array
template <size_t N>
void take_pointer_variable(std::array<int, N> &std_array_ptr) {
    for (int i = 0; i < N; i++) {
        std::cout << "std_array_ptr["<<i<<"]: " << std_array_ptr[i] << " memory reference: " << &std_array_ptr[i] << " de-referenced value: " << std_array_ptr[i] << std::endl;
    }
}

#endif // HELPER_H
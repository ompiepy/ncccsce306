// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: helper.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab 8 - Passing Data and using Pointers
// Description: This file contains the definitions of the overloaded functions.
// --------------------------------------------------------------------------------------

#include <iostream> // Standard Console Input Output
#include <array> // Strandard Array Library
#include <string> // Standard String Library

//Function to accept an integer variable
void take_simple_variable(int my_integer) {
    std::cout << "my_integer: " << my_integer << " memory reference: " << &my_integer << std::endl;
}

//Function to accept a double variable
void take_simple_variable(double my_double) {
    std::cout << "my_double: " << my_double << " memory reference: " << &my_double << std::endl;
}

//Function to accept a string variable
void take_simple_variable(std::string ten_ten) {
    std::cout << "ten_ten: " << ten_ten << " memory reference: " << &ten_ten << std::endl;
}

//Function to accept an integer array
void take_simple_variable(int int_array_five[]) {
    for (int i = 0; i < 5; i++) {
        std::cout << "int_array_five["<<i<<"]: " << int_array_five[i] << " memory reference: " << &int_array_five[i] << std::endl;
    }
}

//Function to accept a standard integer array
template <size_t N>
void take_simple_variable(std::array<int, N> &std_int_array) {
    for (size_t i = 0; i < N; i++) {
        std::cout << "std_int_array["<<i<<"]: " << std_int_array[i] << " memory reference: " << &std_int_array[i] << std::endl;
    }
}

//Create five overloaded functions, named `take_reference_variable`, each intended to accept a different variable type: `int`, `double`, `string`, `int array[]`, and `std::array` (using a template generator).

//Function to accept a reference variable for an integer
void take_reference_variable(int my_int_ref) {
    std::cout << "my_int_ref: " << my_int_ref << " memory reference: " << &my_int_ref << " de-referenced value: " << my_int_ref << std::endl;
}

//Function to accept a reference variable for a double
void take_reference_variable(double my_dbl_ref) {
    std::cout << "my_dbl_ref: " << my_dbl_ref << " memory reference: " << &my_dbl_ref << " de-referenced value: " << my_dbl_ref << std::endl;
}   

//Function to accept a reference variable for a string
void take_reference_variable(std::string my_str_ref) {
    std::cout << "my_str_ref: " << my_str_ref << " memory reference: " << &my_str_ref << " de-referenced value: " << my_str_ref << std::endl;
}   

//Function to accept a reference variable for an integer array
void take_reference_variable(int my_array_ref[]) {
    for (int i = 0; i < 5; i++) {
        std::cout << "my_array_ref["<<i<<"]: " << my_array_ref[i] << " memory reference: " << &my_array_ref[i] << " de-referenced value: " << my_array_ref[i] << std::endl;
    }
}

//Function to accept a reference variable for a standard integer array
template <size_t N>
void take_reference_variable(std::array<int, N>& std_array_ref) {
    for (size_t i = 0; i < N; i++) {
        std::cout << "std_array_ref["<<i<<"]: " << std_array_ref[i] << " memory reference: " << &std_array_ref[i] << " de-referenced value: " << std_array_ref[i] << std::endl;
    }
}

//Function to accept a pointer variable for an integer
void take_pointer_variable(int my_int_ptr) {
    std::cout << "my_int_ptr: " << my_int_ptr << " memory reference: " << &my_int_ptr << " de-referenced value: " << my_int_ptr << std::endl;
}

//Function to accept a pointer variable for a double
void take_pointer_variable(double my_dbl_ptr) {
    std::cout << "my_dbl_ptr: " << my_dbl_ptr << " memory reference: " << &my_dbl_ptr << " de-referenced value: " << my_dbl_ptr << std::endl;
}

//Function to accept a pointer variable for a string
void take_pointer_variable(std::string my_str_ptr) {
    std::cout << "my_str_ptr: " << my_str_ptr << " memory reference: " << &my_str_ptr << " de-referenced value: " << my_str_ptr << std::endl;
}

//Function to accept a pointer variable for an integer array
void take_pointer_variable(int my_array_ptr[]) {
    for (int i = 0; i < 5; i++) {
        std::cout << "my_array_ptr["<<i<<"]: " << my_array_ptr[i] << " memory reference: " << &my_array_ptr[i] << " de-referenced value: " << my_array_ptr[i] << std::endl;
    }
}

//Function to accept a pointer variable for a standard integer array
template <size_t N>
void take_pointer_variable(std::array<int, N> &std_array_ptr) {
    for (size_t i = 0; i < N; i++) {
        std::cout << "std_array_ptr["<<i<<"]: " << std_array_ptr[i] << " memory reference: " << &std_array_ptr[i] << " de-referenced value: " << std_array_ptr[i] << std::endl;
    }
}

//Function to accept a smart pointer for an integer
void take_smart_pointer_variable(int my_int_sptr) {
    std::cout << "my_int_sptr: " << my_int_sptr << " memory reference: " << &my_int_sptr << " de-referenced value: " << my_int_sptr << std::endl;
}

//Function to accept a smart pointer for a double
void take_smart_pointer_variable(double my_dbl_sptr) {
    std::cout << "my_dbl_sptr: " << my_dbl_sptr << " memory reference: " << &my_dbl_sptr << " de-referenced value: " << my_dbl_sptr << std::endl;
}

//Function to accept a smart pointer for a string
void take_smart_pointer_variable(std::string my_str_sptr) {
    std::cout << "my_str_sptr: " << my_str_sptr << " memory reference: " << &my_str_sptr << " de-referenced value: " << my_str_sptr << std::endl;
}

//Function to accept a smart pointer for an std array
void take_smart_pointer_variable(int my_array_sptr[]) {
    for (int i = 0; i < 5; i++) {
        std::cout << "my_array_sptr["<<i<<"]: " << my_array_sptr[i] << " memory reference: " << &my_array_sptr[i] << " de-referenced value: " << my_array_sptr[i] << std::endl;
    }
}

// Smart pointer to a std::array (using std::shared_ptr)
template <size_t N>
void take_smart_pointer_variable(std::array<int, N> &std_array_sptr) {
    for (size_t i = 0; i < N; i++) {
        std::cout << "std_array_sptr["<<i<<"]: " << std_array_sptr[i] << " memory reference: " << &std_array_sptr[i] << " de-referenced value: " << std_array_sptr[i] << std::endl;
    }
}
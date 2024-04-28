// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: main.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab 8: Passing Values, References, and Pointers to Functions
// Description: This lab This lab focuses on creating overloaded functions that
// accept different variable types (simple, reference, and pointer variables) and
// calling these functions from the `main()` function.
// --------------------------------------------------------------------------------------

#include <iostream> // Standard Console Input Output
#include <array>	// Strandard Array Library
#include <string>	// Standard String Library
#include "helper.h" // Include the helper.h file
//#include "final.cpp"

int main(int argc, char **argv)
{
	// Initialize the variables
	int my_integer = 11;									 // Integer Variable
	double my_double = 11.11;								 // Double Variable
	std::string ten_ten = "ten ten";						 // String Variable
	int int_array_five[5] = {0, 1, 2, 3, 4};				 // Integer Array
	std::array<int, 5> std_int_array = {10, 11, 12, 13, 14}; // Standard Integer Array

	// Call each overloaded function with the initial variables as arguments
	take_simple_variable(my_integer);
	take_simple_variable(my_double);
	take_simple_variable(ten_ten);
	take_simple_variable(int_array_five);
	take_simple_variable<5>(std_int_array);

	// // Print the value and memory reference of each variable
	// std::cout << "my_integer: " << my_integer << " memory reference: " << &my_integer << std::endl;
	// std::cout << "my_double: " << my_double << " memory reference: " << &my_double << std::endl;
	// std::cout << "ten_ten: " << ten_ten << " memory reference: " << &ten_ten << std::endl;

	// Print the value and memory reference of each element in the arrays
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << "int_array_five[" << i << "]: " << int_array_five[i] << " memory reference: " << &int_array_five[i] << std::endl;
	// }

	// //Print the value and memory reference of each element in the standard Integer Array
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << "std_int_array[" << i << "]: " << std_int_array[i] << " memory reference: " << &std_int_array[i] << std::endl;
	// }

	std::cout << std::endl;

	// Creating the reference variables for each declared variable
	int &my_int_ref = my_integer;					   // Reference Variable for Integer
	double &my_dbl_ref = my_double;					   // Reference Variable for Double
	std::string &my_str_ref = ten_ten;				   // Reference Variable for String
	int(&my_array_ref)[5] = int_array_five;			   // Reference Variable for Integer Array
	std::array<int, 5> &std_array_ref = std_int_array; // Reference Variable for Standard Integer Array

	// Print the initial variable's value and its memory location using the reference variables. Additionally, print the de-referenced value of the reference variables. Provide clear titles and labels. Use loops to print values in both arrays.
	//std::cout << "my_int_ref: " << my_integer << " memory reference: " << &my_int_ref << " de-referenced value: " << my_int_ref << std::endl;
	//std::cout << "my_dbl_ref: " << my_double << " memory reference: " << &my_dbl_ref << " de-referenced value: " << my_dbl_ref << std::endl;
	//std::cout << "my_str_ref: " << ten_ten << " memory reference: " << &my_str_ref << " de-referenced value: " << my_str_ref << std::endl;

	// //Print the value and memory reference of each element in the arrays
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << "my_array_ref[" << i << "]: " << int_array_five[i] << " memory reference: " << &my_array_ref[i] << " de-referenced value: " << my_array_ref[i] << std::endl;
	// }

	// //Print the value and memory reference of each element in the standard Integer Array
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << "std_array_ref[" << i << "]: " << std_int_array[i] << " memory reference: " << &std_array_ref[i] << " de-referenced value: " << std_array_ref[i] << std::endl;
	// }

	// Call each overloaded function with the reference variables as arguments
	take_reference_variable(my_int_ref);
	take_reference_variable(my_dbl_ref);
	take_reference_variable(my_str_ref);
	take_reference_variable(my_array_ref);
	take_reference_variable<5>(std_array_ref);
	std::cout << std::endl;

	// Create pointer variable that points to the memory locations or each initial variable
	int *my_int_ptr = &my_integer;			   // Pointer Variable for Integer
	double *my_dbl_ptr = &my_double;		   // Pointer Variable for Double
	std::string *my_str_ptr = &ten_ten;		   // Pointer Variable for String
	int *my_array_ptr = int_array_five;		   // Pointer to the first element of the Integer Array
	// int *std_array_ptr = std_int_array; // Pointer to the first element of the standard Integer Array

	// //Print the initial variable's value and the de-referenced memory locations using the pointer variables. Additionally, print the value of the pointer variables. Use descriptive titles, labels, and loops for array values.
	// std::cout << "my_int_ptr: " << my_integer << " memory reference: " << &my_int_ptr << " de-referenced value: " << *my_int_ptr << std::endl;
	// std::cout << "my_dbl_ptr: " << my_double << " memory reference: " << &my_dbl_ptr << " de-referenced value: " << *my_dbl_ptr << std::endl;
	// std::cout << "my_str_ptr: " << ten_ten << " memory reference: " << &my_str_ptr << " de-referenced value: " << *my_str_ptr << std::endl;

	// //Print the value and memory reference of each element in the arrays
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << "my_array_ptr[" << i << "]: " << int_array_five[i] << " memory reference: " << &my_array_ptr[i] << " de-referenced value: " << my_array_ptr[i] << std::endl;
	// }

	// //Print the value and memory reference of each element in the standard Integer Array
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << "std_array_ptr[" << i << "]: " << std_int_array[i] << " memory reference: " << &std_array_ptr[i] << " de-referenced value: " << std_array_ptr[i] << std::endl;
	// }

	// Call each overloaded function with the pointer variables as arguments
	take_pointer_variable(*my_int_ptr);
	take_pointer_variable(*my_dbl_ptr);
	take_pointer_variable(*my_str_ptr);
	take_pointer_variable(my_array_ptr);
	take_pointer_variable<5>(std_int_array);

	//call_eight_lab();
	return 0;
}
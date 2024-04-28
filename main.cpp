// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: main.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab 8 - Passing Data and using Pointers
// Description: This lab This lab focuses on creating overloaded functions that
// accept different variable types (simple, reference, and pointer variables) and
// calling these functions from the `main()` function.
// --------------------------------------------------------------------------------------

#include <iostream> // Standard Console Input Output
#include <array>	// Strandard Array Library
#include <string>	// Standard String Library
#include "helper.h" // Include the helper.h file
# include <memory> // Standard Memory Library
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
	std::cout << std::endl;

	// Creating the reference variables for each declared variable
	int &my_int_ref = my_integer;					   // Reference Variable for Integer
	double &my_dbl_ref = my_double;					   // Reference Variable for Double
	std::string &my_str_ref = ten_ten;				   // Reference Variable for String
	int(&my_array_ref)[5] = int_array_five;			   // Reference Variable for Integer Array
	std::array<int, 5> &std_array_ref = std_int_array; // Reference Variable for Standard Integer Array

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
	
	// Call each overloaded function with the pointer variables as arguments
	take_pointer_variable(*my_int_ptr);
	take_pointer_variable(*my_dbl_ptr);
	take_pointer_variable(*my_str_ptr);
	take_pointer_variable(my_array_ptr);
	take_pointer_variable<5>(std_int_array);
	std::cout << std::endl;

	//Create a smart pointer variable that points to the memory location of each variable
	std::unique_ptr<int> my_int_sptr = std::make_unique<int>(my_integer); // Smart Pointer for Integer
	
 	// Smart Pointer Variable for Double
	std::unique_ptr<double> my_dbl_sptr = std::make_unique<double>(my_double);

	// Smart Pointer Variable for String
	std::unique_ptr<std::string> my_str_sptr = std::make_unique<std::string>(ten_ten);

	// Smart Pointer Variable for Integer Array
	std::unique_ptr<int[]> my_array_sptr = std::make_unique<int[]>(5);

	// Smart Pointer Variable for Standard Integer Array
	std::unique_ptr<std::array<int, 5>> std_array_sptr = std::make_unique<std::array<int, 5>>();

	std::copy(std::begin(int_array_five), std::end(int_array_five), std_array_sptr->begin());
	// Smart pointer to a std::array (using std::shared_ptr)
	std::shared_ptr<std::array<int, 5>> smart_std_array_ptr = std::make_shared<std::array<int, 5>>(std_int_array);

	// Smart pointers offer automatic memory management and ownership semantics, 
	//reducing the risk of memory-related errors in C++ programs.

	// Call each overloaded function with the smart pointer variables as arguments
	take_smart_pointer_variable(*my_int_sptr);
	take_smart_pointer_variable(*my_dbl_sptr);
	take_smart_pointer_variable(*my_str_sptr);
	take_smart_pointer_variable(std_array_sptr->data());
	take_smart_pointer_variable<5>(*smart_std_array_ptr);
	return 0;
}
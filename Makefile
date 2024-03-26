# --------------------------------------------------------------------------------------
# Author: Om Sharma
# File Name: Makefile
# NCC CSCE 306 1 - OO Software Development
# Lab #5 - Fruit Class File in C++
# Description: This file automates the building and running the cpp files.
# --------------------------------------------------------------------------------------

# Default is to run command defined by "run"
default: run

# Compiles with the flag -lcurl
# Run the application
run:
	@g++ -o fruit main.cpp fruit.h fruit.cpp mycurl.h mycurl.cpp -lcurl
	@./fruit $(API_KEY)
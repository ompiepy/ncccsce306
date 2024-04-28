# --------------------------------------------------------------------------------------
# Author: Om Sharma
# File Name: Makefile
# NCC CSCE 306 1 - OO Software Development
# Lab #7 - Variables, Reference Variables, and Pointer Variables (Limited Scope)
# Description: This is a makefile to compile and run the application
# --------------------------------------------------------------------------------------

# Default is to run command defined by "run"
default: run

# Compiles with the flag -lcurl
# Run the application
run:
	@g++ -o a main.cpp helper.h helper.cpp
	@./a
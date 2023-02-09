#pragma once
#include <iostream>

using namespace std;
const int MAX_ARRAY_VALUE = 50;					//The max number of rows/columns alotted to the program. Exceeding will corrupt the stack.

class Array {
public:											//public member functions
	Array();									//default array case
	Array(int rows, int columns);
	void searchArray(double searchValue);
	void setUserArray();						//Changes a specific value in the array given the user-defined position
	void const displayArray();					//displays the array in row-by-column form
	void addToArray(int rows, int columns);		//modifies the row and column count of an existing array, then fills in missing spaces with user input
	void nukeValue(int rows, int columns);		//changes the value at the given index to 0

private:										//private member functions and values
	int rows;									//How many rows the array has
	int columns;								//How many columns the array has
	double searchValue;
	int functionArray[MAX_ARRAY_VALUE][MAX_ARRAY_VALUE];			//The actual array that is modified throughout the program
	bool errorThrown;							//A flag to tell certain functions when an error has occurred to prevent the program from printing
												//corrupted information.
};
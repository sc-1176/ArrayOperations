#include "Array.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*
* NOTE BEFORE RUNNING: Error codes that are thrown are tied to specific functions. Quick Access key is as follows.
* 0xx - error initilizing an array
* 1xx - error in 'addToArray'
* 2xx - error in 'setUserArray'
*/


//default initializing class
Array::Array() {
	rows = 1;
	columns = 1;
	functionArray[1][1] = {0};
	errorThrown = false;
	searchValue = 0;
}

/*initilizing class, accepts input for how many rows and columns the desired array should have
then reads information from an input file to create a matrix of the desired size*/
Array::Array(int ArrayRows, int ArrayColumns) {

	rows = ArrayRows;
	columns = ArrayColumns;						// rows and columns adjust the size of the array below the max

	const int arrRows = rows;					//constant integers since that's all an array accepts
	const int arrCol = columns;

	functionArray[arrRows][arrCol] = {0};		//clearing out the array
	errorThrown = false;						//setting up a default flag to see when errors are thrown
												/*
												* NOTE: the 'error thrown' flag is important for the program's display function,
												* but is not vital in any other portion of the code.
												*/
	searchValue = 0;							//initilizing the value for the search function


	fstream arrayData;							//creating a file input stream
	arrayData.open("ArrayData.txt");			//opening a the input file
	if (!arrayData) {							//if there's no input file, throw an error
		errorThrown = true;
		cout << "Error opening file." << endl;
	}
	try {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					if (arrayData.eof())		//check to make sure the function hasn't hit the end of the input file
					{
						errorThrown = true;		//if it has, throw an error with a unique error code
						throw 001;
					}
					else {
						arrayData >> functionArray[i][j];	//filling the array in with data from the input file
					}
				}
			}
	}
	catch (int exceptionNum) {					//printing the error for the user
		cout << "Your array size has exceeded the amount of values in your input file." << endl
			<< "Error Code: " << exceptionNum;
	}

	arrayData.close();							//closing the input file after use
}

/*searches the current matrix for a certain number and prints out the index of said number if the number 
is present in the matrix */
void Array::searchArray(double search) {

	bool itemFound = false;						//initilizing a flag to check whether or not the item has already been found in the matrix
	searchValue = search;						//setting 'searchValue' equal to the value that's being searched for
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (functionArray[i][j] == search)	//check to see if the item at the current index is equal to the desired search term
			{
				cout << "The index of " << search		
					<< " in the matrix is (" << i << ',' << j << ")." 
					<< endl;					//printing the location
				itemFound = true;				//notify the program that the searched for value has been found
			}
		}
	}
	if (itemFound == false) {					//check to see if the searched for value was never found
		cout << "This value does not exist in your current matrix." << endl;
	}
}

/*Adds on either a column or a row then prompts the user to fill in missing data
  does NOT read from the input file, will only GROW an array, NOT shrink one*/
void Array::addToArray(int userRows, int userColumns) {
	const int addedRows = userRows + rows;						//sets the new TOTAL amount of rows
	const int addedCol = userColumns + columns;					//sets the new TOTAL amount of columns

	try {
		if (addedRows >= rows && addedCol >= columns) {			//checks to make sure userRows and userColumns are not negative integers
			if (addedRows < MAX_ARRAY_VALUE && addedCol < MAX_ARRAY_VALUE)	//checks to make sure the new number of rows and columns does not exceed the max alotted memory space
			{
				for (int i = 0; i < addedRows; i++) {			//iterates through only the amount of rows that were added
					for (int j = 0; j < addedCol; j++) {		//iterates through only the amount of columns that were added
						if (i >= rows || j >= columns) {		//makes sure the user doesn't write over any existing values in the previous array
							cout << "Input the desired value for index (" << i << ',' << j << "): " 
								<< endl;						//prompts the user to input new values while outputting the current index
							cin >> functionArray[i][j];	
						}
					}
				}
				rows = addedRows;								//changes the universal row value to the new size
				columns = addedCol;								//changes the universal column value to the new size

			}
			else
			{
				errorThrown = true;								//new array has exceeded the max memory space
				throw 101;
			}
		}
		else														
		{
			errorThrown = true;									//either userRows or userColumns was negative
			throw 102;
		}
	}
	catch (int exceptionNum) {
		cout << "There was an issue adjusting your array size. Please make sure your total array size is less than 50 rows and 50 columns, and that your values are nonzero."
			<< endl;
		cout << "Error Code: " << exceptionNum;
	}
}

//replaces array values with user-inputted variables
void Array::setUserArray() {
	int rowPosition;										//intilizing values for user input
	int columnPosition;
	int replacementNum;

	cout << "To replace the value of an entry, please provide the row and column position, starting from 0 to your array size."
		 << endl << endl;
	cout << "What is the row position to be replaced? Row:	";
	cin >> rowPosition;
	cout << endl << "what is the column position to be replaced? Column:	";
	cin >> columnPosition;
	cout << endl << "What value are you replacing this number with?	";
	cin >> replacementNum;
	try {
		if (columnPosition >= 0 && rowPosition >= 0) {		//check that the entered index isn't out of bounds
			if (columnPosition < columns && rowPosition < rows) {
															//return both the old value and its index and the new value that will be replacing the old value
				cout << "Old value for position (" << rowPosition << "," << columnPosition << ") is "
					<< functionArray[rowPosition][columnPosition] << endl << "The New value is: " <<
					replacementNum << endl;
			}
			else if (columnPosition >= rows || rowPosition >= rows) {
				errorThrown = true;							//throws an error if the index is above the upper bound
				throw 201;
			}
			else {											//emergency error throw for catastrophic and confusing errors
				errorThrown = true;
				throw 202;
			}
		}
		else {												//throws an error if the index is negative
			errorThrown = true;
			throw 203;
		}
	}
	catch (int exceptionNum) {
		cout << "Sorry, that position is outside the selected matrix." << endl
			<< "Error Code: " << exceptionNum << endl << endl;
	}

	try {
		if (errorThrown == false)							//replaces the value IF AND ONLY IF the program has not called an error so far
		{
			functionArray[rowPosition][columnPosition] = replacementNum;
		}
		else {
			throw 204;										//Notifies the user their value has not been replaced
		}
	}
	catch (int exceptionNum) {
		cout << "Unable to replace value, position out of bounds." << endl;
		cout << "Error Code: " << exceptionNum << endl << endl;
	}
}

//turns a value to '0' when given the index
void Array::nukeValue(int rowPosition, int colPosition) {
	
	if (rowPosition >= 0 && rowPosition < rows) {				//checks that the row index isn't out of bounds
		if (colPosition >= 0 && colPosition < columns)			//checks that the column index isn't out of bounds
		{
			functionArray[rowPosition][colPosition] = 0;		//replaces the value at that index with 0
		}
	}
	else {
		cout << "Invalid index." << endl;						//failsafe if the index doesn't exist
	}
}

/*display function
this does not print an array if an error has been thrown anywhere previously in the code*/
void const Array::displayArray() {
	
	if (errorThrown == true) {					//checks to see if an error has been thrown ANYWHERE in the program
		cout << endl << "Please revise the above errors and reprint." 
			<< endl << endl;					//prompts the user to fix errors - function exits without printing
	}
	else if (errorThrown == false) {			//if no errors have been detected, print as normal
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << setw(7) << functionArray[i][j];
				if (j == columns - 1)			//creates a new line at the end of row
				{
					cout << endl;
				}
			}
		}
	}
	cout << endl;
}

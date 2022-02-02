//****************************************************
// Lab: Validate Sudoku.
// Name: 
// ADM:
// Fall 2021
//****************************************************



#include <iostream>
#include <fstream>
#include "validate.h"
using namespace std;


int main()
{	

	//Global class variables 
	ifstream inputFile;
	bool isValid = true;

	int sudoku2D[9][9];

	//Opening the input fle
	inputFile.open("dummyInput.txt");


	//Loop through the file to feed our array vector.
	if (!inputFile.eof())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				inputFile >> sudoku2D[i][j];
			}
		}
	}

	// Printing out the sudoku numbers from the 2D array vector 
	cout << "\n**********************************\n";
	cout << "\nSudoku Table: \n";
	cout << "**********************************\n";
	for (int i = 0; i < 9; i++) {
		cout << "| ";

		for (int j = 0; j < 9; j++)
		{
			cout << sudoku2D[i][j];
			cout << " ";

			// forming the sections with the modulus 3
			if ((j + 1) % 3 == 0)
			{
				cout << " | ";
			}
		}

		cout << endl;

		// forming the sections with the modulus 3
		if ((i + 1) % 3 == 0) {
			cout << "**********************************\n";
		}
	}

	//Validate the sudoku by calling the validate function from validate.cpp
	ValidateSudoku(sudoku2D);

	inputFile.close();
}

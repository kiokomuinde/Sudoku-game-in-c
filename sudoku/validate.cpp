
//****************************************************
// Lab: Validate Sudoku.
// Name: 
// ADM:
// Fall 2021
//****************************************************

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
// Method to validate the sudoku from the input file
void ValidateSudoku(int sudoku2D[9][9])
{
	string finalValidityText = "\nIts a valid sudoku.";
    

    //Array to be used to check any repeting numbers in our sudoku code.
    int arr[] = {0,0,0,0,0,0,0,0,0};
    string validityText = "";

    //Integers to be used as counter in our loops
    int j = 0, i = 0;

    cout << "\n**********************************\n";
    //Looping through our sudoku elements.
    for(i=0; i<9; i++){

    	for (j = 0; j < 9; ++j)
    	{
    		

	        //Check for any out of range number in the sudoku and output to the console. Then return.
	        if(sudoku2D[i][j] < 10 && sudoku2D[i][j] > 0){

	            //Validate every instance of the sudoku number. If it appears twice output the message to the stdout. Then return.
	            if(arr[sudoku2D[i][j] -1] == 0){

	                arr[sudoku2D[i][j] -1] = sudoku2D[i][j];
	                validityText = "Row " + to_string(i+1) +": Is Valid\n";
	            }else{

	                validityText = "Row " + to_string(i+1) +": Its not a valid sudoku. " + to_string(sudoku2D[i][j]) + " is appearing more than once.\n";
	            	finalValidityText = "\nIts not a valid sudoku.";
	            	break;
	            }



	        }else{

	            validityText = "Row " + to_string(i+1) +": Its not a valid sudoku. "+ to_string(sudoku2D[i][j]) + " is not in the range 1 - 9.\n";
	        	finalValidityText = "\nIts not a valid sudoku.";
	        	break;
	        }


	    }

	    // Resetting check array for reuse
	    std::fill(std::begin(arr), std::end(arr), 0);
	    cout <<validityText;

    }

    cout << "**********************************\n";

    cout << "\n**********************************\n";
    //Looping through our sudoku elements.
    for(i=0; i<9; i++){

    	for (j = 0; j < 9; ++j)
    	{
    		
	        //Check for any out of range number in the sudoku and output to the console. Then return.
	        // Switching i and j to represent columns instead of rows
	        if(sudoku2D[j][i] < 10 && sudoku2D[j][i] > 0){

	            //Validate every instance of the sudoku number. If it appears twice output the message to the stdout. Then return.
	            if(arr[sudoku2D[j][i] -1] == 0){

	                arr[sudoku2D[j][i] -1] = sudoku2D[j][i];
	                validityText = "Column " + to_string(i+1) +": Is Valid\n";
	            }else{

	                validityText = "Column " + to_string(i+1)+ ": Its not a valid sudoku. " + to_string(sudoku2D[j][i]) + " is appearing more than once.\n";
	            	finalValidityText = "\nIts not a valid sudoku.";
	            	break;
	            }



	        }else{

	            validityText = "Column " + to_string(i+1)+ ": Its not a valid sudoku. "+ to_string(sudoku2D[j][i]) + " is not in the range 1 - 9.\n";
	        	finalValidityText = "\nIts not a valid sudoku.";
	        	break;
	        }


	    }

	    // Resetting check array for reuse
	    std::fill(std::begin(arr), std::end(arr), 0);
	    cout <<validityText;

    }

    cout << "**********************************\n";




    cout << "\n**********************************\n";

    bool validSection = true;
    int sectionNum = 1;

	// Creating a one dimension vector to store a section
	vector<int> currentSection;

	// Filling our vector with the data to be processed.
	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			for (int sectionRow = i; sectionRow < i + 3; sectionRow++)
			{
				for (int sectionCol = j; sectionCol < j + 3; sectionCol++)
					currentSection.push_back(sudoku2D[sectionRow][sectionCol]);
			}

			//Sorting our vector to be tested to check for repeating itegers.
			sort(currentSection.begin(), currentSection.end());

			for (int index = 0; index < 9; index++)
			{
				if (currentSection.at(index) > 9 || currentSection.at(index) < 1)
				{
					validSection = false;
					validityText = "Section " + to_string(sectionNum++) +": Its not a valid sudoku. "+ to_string(currentSection.at(index)) + " is not in the range 1 - 9.\n";
	        		finalValidityText = "\nIts not a valid sudoku.";
				}
				else if (index != 8)
				{
					if (currentSection.at(index) == currentSection.at(index + 1))
					{
						validSection = false;
						validityText = "Section " + to_string(sectionNum++) +": Its not a valid sudoku. "+ to_string(currentSection.at(index)) + " is not in the range 1 - 9.\n";
	        			finalValidityText = "\nIts not a valid sudoku.";
					}
				}

				
			}

			// Storing the validity status
				if (validSection)
				{
					validityText = "Section " + to_string(sectionNum++) +": Is Valid\n";
				}

			// Resetting variables for reuse
			cout <<validityText;
			currentSection.clear();
			validSection = true;

		}
	}

	cout << "**********************************\n";

	cout << "\n**********************************";

    // Give the final remarks about the validity of the sudoku
    cout << finalValidityText;

}

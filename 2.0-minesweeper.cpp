/****************************
Below is the pseudocode for a program. A template is under that with comments to show you what to add. Some of the is already there, some of it isn't. Add what is missing and submit the code file. The code does not have comments, so you get used to interpretting the code and syntax.

Pseudocode:
	Load in the grid
	
	Repeat until the game is won or lost entirely
		Ask the user to choose a location
		Check if the location is valid 
		If the user chose an invalid location (outside 0-9), ask again
		If the user chose a valid location
			If user chose a location with a Mine, tell them they failed and hit a mine, replace with a B (for "bang")
			If user chose a location that is a '-', mark the location with an S (for "safe") in the grid and tell them they win!
	Print the grid with changed values.

****************************/

#include <iostream>
#include <fstream>

int main(){   
	
	std::ifstream inputFile("2.0-grid.txt");

	char grid[10][10];
	
	int anotherRound = 1; 
	
	int counter = 0; 

	/* Fill the grid using the inputFile */

	int userRow, userCol = 0;
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			inputFile >> grid[j][i];
		}
	}
	do{

		/* Use a do-while loop to ask the user for an input and check the user's inputs (make sure they are within the expected range). If not, make them try again */ 

		std::cout << "Enter coordinates to check(x y):";
		std::cin >> userRow >> userCol;
		if( userRow > 10 || userCol > 10){
			std::cout << "Invalid entery try again\n";
		//	anotherRound = 0;
		}
		else if(grid[userRow][userCol] == '-' /*compare the grid at the user coordinates to the letter '-'*/){ 
			grid[userRow][userCol] = 'S'; 
			std::cout << "You chose well!\n";
			counter++;
			if(counter == 10){
				std::cout << "Found all of the mines, you win!\n";
				anotherRound = 0; 
			}
		}
		else if(grid[userRow][userCol] == 'M'){
			std::cout << "Hit a mine, you lose ;-;\n ";
			anotherRound =0;
		}
		/* Fill in the case where you hit a mine (else-if)*/
		
		
	}while(anotherRound);

	/* Print the final grid */
			for(int i =0; i<10; i++){
				for(int j = 0; j<10; j++){
					std::cout << grid[j][i];
				}
				std::cout << "\n";
			}
	inputFile.close(); // always close your files
	return 0; 
} // end of main

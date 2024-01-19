/****************************
Grid Search 

In 2.0-grid.txt, there is a grid of numbers, 1 to 20. Note that there are no numbers outside of that range, and there are some numbers in that range that are not listed.

Your task is to load that grid into a character array in C++.
Once loaded in, the user should be prompted to search for a number.  
The program should (a) find all instances and report what grid coordinates, (b) notify the user if the number is not found anywhere, (c) ask the user if they want to continue (the number 0 will exit the program).

All searches should output to the screen.  The program should check the inputs to make sure they are within the valid 1-20 range. If not, it should ask the user to try again.
****************************/

#include <iostream>
#include <fstream>

int main(){   
	
	std::ifstream inputFile("2.0-gridQuest.txt");

	int grid[8][8];
	
	int anotherRound = 1; 
	
	int counter = 0; 

	/* Fill the grid using the inputFile */

	int userNum = 0;
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			inputFile >> grid[j][i];
		}
	}
	do{
		/*asks user for input and checks if number falls in range*/
		do{
		std::cout << "Enter number to check for(1-20):";
		std::cin >> userNum;
		}while(userNum < 0 || userNum > 21);

		/*Searches grid for number*/

		for(int i = 0; i <= 8; i++){
			for(int j = 0; j <=8; j++){

				/*prints were number is found and when the full grid is searched*/
				if(grid[j][i] == userNum){
					std::cout << "Number found at:" << i << "," << j << std::endl;
					counter++;
				}
				else if(i == 8 && j == 8){
					std::cout << "Full grid searched\n";
					//counter++;
					if(counter == 0){
						std::cout << "Number not found in grid\n";
					}
				}
				//else if(counter = 0){
				//	std::cout << "Number not found in grid\n";
				//} 
			}
		}
	/*asks if the user would like to search again*/
	std::cout << "Would you like to search again?(0-exit, 1-continue):\n";
	std::cin >> anotherRound;
	}while(anotherRound);

	inputFile.close(); // always close your files
	return 0; 
} // end of main


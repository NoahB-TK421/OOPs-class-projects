/************
You are creating a function that will take in a struct. The struct will have a number of rows, a number of columns, and a character. The function will print a grid of the characetrs, based on the 
number of rows and columns.

The function will also return a 1 if the the grid is a perfect square.

Use a function prototype.

************/

#include <iostream>

struct gridParameters_s{
	// Create variables of number of rows and columns and the char
	int rows;
	int col;
	char charactor;
};

// Function prototype goes here for printing a grid

int printGrid(int, int, char);
int isSquare(int,int);

int main(){

	int perfectSquareCount = 0;

	// pre-initializing 3 grids (hard-coded)
	gridParameters_s grid1 = {4, 2, '*'};
	gridParameters_s grid2 = {3, 6, 'O'};
	gridParameters_s grid3 = {2, 2, 'X'};
	
	std::cout << " ------ Grid #1 ----- \n";
	// Call each function and add whether or not it was a square 

	printGrid(grid1.rows, grid1.col, grid1.charactor);
	perfectSquareCount += isSquare(grid1.rows, grid1.col);
	std::cout << " ------ Grid #2 ----- \n";
	// Call each function and add whether or not it was a square

	printGrid(grid2.rows, grid2.col,grid2.charactor);
	perfectSquareCount += isSquare(grid2.rows, grid2.col);
	std::cout << " ------ Grid #3 ----- \n";
	// Call each function and add whether or not it was a square
	
	printGrid(grid3.rows, grid3.col, grid3.charactor);
	perfectSquareCount += isSquare(grid3.rows, grid3.col);
	std::cout << "\nThere is (are) " << perfectSquareCount << " perfect square grid(s).\n";
	
	return 0;
}

// Function defintion goes here

		int printGrid(int a, int b, char c){
			for(int i =0; i <= a; i++){
				for(int j = 0; j<=b; j++){
				std::cout << " " << c << " ";
				}
			std::cout << std::endl;
			}
		}
		
		int isSquare(int a, int b){
			return a==b;
		}

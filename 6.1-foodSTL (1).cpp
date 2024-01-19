/**********
You are making a recipe list. A struct for an ingredient is provided.

Each element should be a struct, as defined below. Fill the vector with at least 3 elements, and print to test. 

struct ingredient_s{
	std::string name;
	float amount;
	std::string measurement; //cup, tsp, tbsp, oz, etc.	
};
**********/
#include <iostream>
#include <vector> // for vector STLs
#include <string>
using namespace std;
struct ingredient_s{
	string name;
	float amount;
	string measurement; //cup, tsp, tbsp, oz, etc.	
};

void print(ingredient_s (&));

int main(){

	// Create a vector made of structs, named recipe

	vector<ingredient_s> recipe;
	// You will populate the struct and then you will push it in
		ingredient_s i1 = {"flour", 2, "cups"};
		ingredient_s i2 = {"Sugar", 1, "cups"};
		ingredient_s i3 = {"Butter", 3, "tbsp"};
	int choice = 0;

	// add some ingredients for a recipe
	recipe.push_back(i1);
	recipe.push_back(i2);
	recipe.push_back(i3);

	do{
		cout << "Would you like to (1) print the recipe, (2) add the ingredient to the bowl and remove it from the queue, or (0) quit?\n";
		cin >> choice;
		switch(choice){
			case 0:
				break;
			case 1: {
				// print out the ingredients of the recipe
				for(int i = 0; i < recipe.size(); i++){
				print(recipe.at(i));
				}
				break;
			} // end case 1
			case 2: {
				// print the first ingredient of the recipe, then pop it
				print(recipe.at(0));
				recipe.erase(recipe.begin());
				break;
			} // end case 2
			default:
				cout << "Invalid entry.\n";
		}
	}while(choice != 0);

	// need to clear and leave the program
	recipe.clear();

	return 0;
}
void print(ingredient_s (&local)){
	cout << local.name << " , " << local.amount << " in " << local.measurement << endl;


	}

/**********
You are creating a Rock Paper Scissors game. You will create a base player of a name, a getName, and a pure virtual turn function.

Below is a beginning a base class and main. Your job is to create derived classes and fill in what is missing.

**********/

#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

enum RPS{ Rock, Paper, Scissors }; // Rock = 1, Paper = 2, Scissors = 3;
using namespace std;
class RPS_player_c{
		protected:
			string name;
		public:
			// create a pure virtual "turn" function
			string getName(){return name;}
			virtual int turn(){}
};

class userPlayer_c :public RPS_player_c{

		public:
			int turn(){
				// The user will put in a 0 for Rock, 1 for Paper, and 2 for Scissors
				// Don't let the value be anything other than 0, 1, or 2
				int choice;
				cout << "enter choice 0 for Rock, 1 for Paper, and 2 for Scissors:" << endl;
				cin >> choice;
				return choice;
			 }
			userPlayer_c(string name){this->name = name;}

};

class compPlayer_c : public RPS_player_c{

		public:
			int turn(){
				// Computer will choose randomly between 0, 1, or 2	
				int num = rand() %2+0;
				cout << "computer choose " << num << endl;
				return num;
			}
			compPlayer_c(){this->name = "Computer";}
};

int main(){

	// Create two objects, one of each
	// Must use an array and pointers
	RPS_player_c *array[2] = {
		new userPlayer_c("Noah"),
		new compPlayer_c()};
	int another = 1;
	int winner = 0;
	do{
		
		// User and Computer need to take a turn/throw
		
		int userThrow = array[0]->turn();
		int compThrow = array[1]->turn();
		if(userThrow == compThrow){
			cout << "Tie! Try again until someone wins \n";
			continue;
		}
		else if(((userThrow = 0) && (compThrow = 2)) || ((userThrow = 1) && (compThrow = 0)) || ((userThrow = 2) && (compThrow = 1)))
			winner = 0;
		else
			winner = 1;
		
		cout << "The winner is " << array[winner]->getName() << endl;
		cout << "\nAnother round? 0 no, 1 yes:  ";
		cin >> another;
	}while(another);


	return 0;
}

/************
A struct must be defined with a title, artist, length in minutes, and release year.  

Create an array of at least four structs. 

You need to create the following functions
	1) a function that fills a single struct at a time from user inputs (inputs gathered in function); 
	2) a function the prints a single struct's components in a legible/organized way (spaces, labels, new lines);
	3) 2 functions that search the array for matching artist or year;
		These will be passing in the array of structs by REFERENCE (explicitly) and will be *overloaded*

Note that artist and title may have spaces, so you will need to use "getline()"

When using getline, you may need cin.ignore(); cin.clear(); 

************/

#include <iostream>
#include <string>
using namespace std;

struct song{
		string title;
		string artist;
		int time;
		int year;
	};

void fillIn(song &);
void printDude(song &);
void comp(song (&)[4], int);
void comp(song (&)[4], string);

int main(){

	struct song songs[4];
	cout << "Press enter to start ";
	for(int i = 0; i < 4; i++){
		cout << "song " << i+1 <<":\n";
		 fillIn(songs[i]);
	}

	cout << endl;

	for(int i = 0; i<4; i++){
		printDude(songs[i]);
		cout << endl;
	}

int choice = 1;
while(choice != 0){
cout << "would you like to search by Year, Title, or Exit?(1, 2, 0): ";
cin >> choice;

switch(choice){
		case 1: {
			int year = 0;
		        cout << "enter the year of the song you want to compair: ";
        		cin >> year;

  			comp(songs, year);
			break;
		}
		case 2: {
			cin.ignore(1,'\n');
			string title;
	        	cout << "enter the title of the song you want to compair: ";
        		getline(cin,title);

		        comp(songs, title);
			break;

		}
		case 0: {
			cout << "Exiting";
			return 0;
		}
		default: {
			std::cout << "invalit input\n";
		}

		}//end switch
	}//end while loop


}//end main

void fillIn(song &local){
	cin.ignore(1,'\n');

	cout << "Enter song title:\n";

	getline(cin,local.title);

	cout << "\nEnter artist:";
	getline(cin,local.artist);

	cout << "\nEnter song length in minutes:";
	cin >> local.time;

	cout << "\nEnter release year of song:";
	cin >> local.year;
}//end fillIn, populates songs with title, artist, time, and year

void printDude(song &local){
 	cout << "title:" <<local.title << endl << "artist:" << local.artist << endl << "song length:" << local.time << endl << "release year:" <<local.year << endl;
}//end printDude, prints out individual song

void comp(song (&local)[4], int year){

	int countYearMatch = 0;

		for(int i = 0; i < 4; i++){
			if(year == local[i].year){
				countYearMatch++;
			}
		}
	if(countYearMatch > 0){
		cout << "Match found for the year!" << endl << countYearMatch << " matches found" << endl;
	}
	else if(countYearMatch == 0){
		cout << "No matches found" << endl;
	}
}//end compair year, compairs all songs to the year searched

void comp(song (&local)[4], string title){

int countTitleMatch = 0;

                for(int i = 0; i < 4; i++){
                        if(title == local[i].title){
                                countTitleMatch++;
                        }
                }

        if(countTitleMatch > 0){
                cout << "Match found for the title!" << endl << countTitleMatch << " matches found" << endl;
        }
        if(countTitleMatch == 0){
                cout << "No matches found" << endl;
        }
}//end compair title, compairs all titles to title searched


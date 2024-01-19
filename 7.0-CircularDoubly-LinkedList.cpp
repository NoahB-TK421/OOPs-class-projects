/**
You will be reusing code from past labs:
	Person/student/faculty (you don't need the intern) classes will come from 5.0 and 6.0
	The data structure functions will partially come from sidequest 7.0 or 7.1
	If you reuse parts of the code - mark in the comments what was reused

You will be creating a circular doubly-linked list from scratch. Do not use existing STL functions - in this case, you are creating them yourself.

Create a class for this list. Note you should use a base pointer for the next and previous pointers. You will not create any person/intern objects (only student or faculty), though. The list class should 
have a head or a tail. 

All students should be in the beginning of the list (add to the head), and faculty should be at the end of the list (add at the tail).

Your class functions must include: addToHead, addToTail, remove by name, search for name, print everything, and delete all.

Fully test the functions and class using a main. A general structure is provided below, but can be changed as necessary to fit your coding needs.

Remember the attributes of a circular doubly-linked list: 
- Head points to the first element
- Tail points to the last element
- The last element's next points to Head
- The first element's previous points to Tail
**/
#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <list>
#include <fstream>

using namespace std;

struct date{
		int month;
		int year;
};//reused

class person{
		public:
			person *next;
			person *prev;
			string name, ddm;
			person(){ fillIn();}
			person(string tempName, string tempDDM){ setName(tempName); setDDM(tempDDM);}
			virtual void print(){cout << "Name: " << name << endl << "division:" << ddm << endl;}
			void setName(string tempName){ name = tempName;}
			void setDDM(string tempDDM){ddm = tempDDM;}
			string getDDM(){return ddm;}
			string getName(){return name;}

			virtual void fillIn(){
	                        cin.ignore();
	                        cout << "Enter name:\n";
        	                getline(cin,name);
	                        cout << "\nEnter division/department/major:";
        	                getline(cin,ddm);
                        }//end fillIn for person



			~person(){cout << name << " went to the store and didnt come back." << endl;}
};//resued

date dateOfGraduation = {4,2002};


class student :public person{
		private: int a,b;
		public:
			student *next;
			student *prev;
			date graduationDate;
//			date dateOfGraduation = {4,2002};
			string minor;
			student(){ fillIn();}
			student(string tempName, string tempDDM, int tempGradMonth, int tempGradYear, string tempMinor ):person(tempName,tempDDM){
				 setGradDate(tempGradMonth, tempGradYear); setMinor(tempMinor);}
			void print(){this->person::print(); cout << "Graduation date:"; getDate(); cout  << endl << "Minor:" << minor << endl<< endl;}

			void setGradDate(int tempMonth, int tempYear){
				graduationDate.month = tempMonth; 
				graduationDate.year = tempYear;
			}

			void setMinor(string tempMinor){minor = tempMinor;}
			void getDate(){ cout << graduationDate.month << "-" << graduationDate.year << endl << "months and years till graduation:" << graduationDate.month-dateOfGraduation.month << "-" << graduationDate.year-dateOfGraduation.year;}
			string getMinor(){return minor;}

			void fillIn(){
//			        this->person::fillIn();

			        cout <<"\nEnter graduation month:";
			        cin >> a;
				cout <<"\nEnter graduation year:";
				cin >> b;
				setGradDate(a,b);

				cout << "\nEnter minor";
				cin.ignore();
			        getline(cin, minor);
		        }//end fillIn for student

			~student(){cout << name << " decided to drop out." << endl;}
};//reused

class facalty :public person{
		private: int a,b;
		public:
			facalty *next;
			facalty *prev;
			date startDate;
			string title;
			facalty(){ fillIn();}
			facalty(string tempName, string tempDDM, int tempMonth, int tempYear, string tempTitle):person(tempName,tempDDM){ setStartDate(tempMonth,tempYear); setTitle(tempTitle);}
			void print(){this->person::print(); cout << "Start date:"; getDate(); cout << endl << "Title:" << title << endl<<endl;}
			void  setStartDate(int tempMonth, int tempYear){startDate.month = tempMonth; startDate.year = tempYear;}
			void setTitle(string tempTitle){title = tempTitle;}
			void getDate(){cout << startDate.month << "-" <<startDate.year;}
			string getTitle(){return title;}

			void fillIn(){
//				this->person::fillIn();

				cout << "\nEnter title:";
				getline(cin, title);

			        cout <<"\nEnter start date month:";
			        cin >> a;
				cout <<"\nEnter start date year:";
				cin >> b;
			        setStartDate(a,b);
		        }//end fillIn for facalty


			~facalty(){cout << name << " got sick of their students shit." << endl;}
};//reused

class list_c{
	protected:
		person *Head, *Tail;
	public:
		void addToHead(){

			if(Head == NULL){
                                person* temp = new student();
                                temp->next = temp->prev = temp;
                                Head = temp;
                                return;

                        }

			person* temp = new student();

			temp->next = Head;
			temp->prev = Tail;
			Tail->next = Head->prev = temp;
			Head = temp;
		}

		void addToHead(string tempName, string tempDDM, int tempGradMonth, int tempGradYear, string tempMinor ){
			Tail = Head->prev;

			if(Head == NULL){
				person* temp = new student(tempName, tempDDM, tempGradMonth, tempGradYear, tempMinor);
				temp->next = temp->prev = temp;
                                Head = temp;
                                return;

			}

			person* temp = new student(tempName, tempDDM, tempGradMonth, tempGradYear, tempMinor);

                        temp->next = Head;
                        temp->prev = Tail;

			Tail->next = Head->prev = temp;

                        Head = temp;

		}

		void addToTail(){
			Tail = Head->prev;
			person* temp = new facalty();

                        if(Head == NULL){

                                temp->next = temp->prev = temp;
                                Head = temp;
                                return;
                        }

                        temp->next = Head;

			Head->prev = temp;

                        temp->prev = Tail;

			Tail->next = temp;

		}

		 void addToTail(string tempName, string tempDDM, int tempMonth, int tempYear, string tempTitle){

                        if(Head == NULL){
				person* temp = new facalty(tempName, tempDDM, tempMonth, tempYear, tempTitle);

                                temp->next = temp->prev = temp;
                                Head = temp;
				return;
                        }

			Tail = Head->prev;
			person* temp = new facalty(tempName, tempDDM, tempMonth, tempYear, tempTitle);

			temp->next = Head;

                        Head->prev = temp;

                        temp->prev = Tail;

                        Tail->next = temp;

              }

		void remove(string nameToRemove){
			if(Head == NULL) return;

			if(Head->getName()==nameToRemove && Head->next==Head){
				delete(Head);
				Head=NULL;
				return;
			}

			if(Tail->getName()==nameToRemove && Tail->next==Tail){
				delete(Tail);
				Tail=NULL;
				return;
			}

			person* temp = Head;

			if(Head->getName()==nameToRemove){
				do{
					temp = temp->next;
				}while(temp->next !=Head);

				temp->next = Head->next;
				delete(Head);
				Head = temp->next;
				return;
			}

			while(temp->next !=Head && temp->next->getName() != nameToRemove){ temp=temp->next; }

			if(temp->next->getName() == nameToRemove){
				person* hold = temp->next;
				temp->next=hold->next;
				cout << nameToRemove << " deleted from list\n";
				delete(hold);
				cout <<"\nList after deleting\n";
				list_c::printAll();
				return;
			}else{
				cout << nameToRemove <<" not found\n";
			}
		}

		void deleteAll(){
			person* temp = Head;
			do{
				temp = temp->next;
			}while(temp->next != Head);
			temp->next = NULL; // remove the circular nature
			temp = Head;
			person* hold;
			while(temp){
				hold = temp;
				temp = temp->next;
				delete hold;
			}
			Head = NULL;
		}

		void search(string nameToSearch){
			int found = 0;
			person* temp = Head;
		do{
			if(nameToSearch == temp->getName()){
				temp->print();
				cout << endl;
				found = 1;
			}
			temp = temp->next;
		}while(temp != Head);
		if(!found)
			cout << "Not found.\n";
		}

		void printAll(){
			person* temp = Head;
			do{
				temp->print();
				temp = temp->next;
			}while(temp != Head);
		}
		list_c(){
			Head = NULL;
			Tail = NULL;
		}
		~list_c(){
			deleteAll();
		}
};

int main(){
	
	int choice;
	
	list_c FullList; 
//	cout << "1\n";
	FullList.addToTail("Bruce Gyngell", "Philosophy", 10, 1999, "Professor");
	FullList.addToHead("Steve Irwin", "Allegator studies", 4,1999,"Wholsomeness");
//	FullList.addToTail("Bruce Gyngell", "Philosophy", 10, 1999, "Professor");
	//reused menu system 
	do{
		cout << "would you like to:\n1: add student/facalty/intern\n2: search\n3: print all\n4:delete all\n5:remove entry\n" << endl;
	cin >> choice;

		switch(choice){
			case 1:{
				int choice1;
				cout <<"would you like to add a:\n1: student\n2:facalty\n";
				cin >> choice1;
			switch(choice1){
				case 1:{
					FullList.addToHead();
					break;
					}
				case 2:{
					FullList.addToTail();
					break;
					}
				default:{
					cout << "how did you get here? youre not supposed to do that" << endl;
					}
			}//end switch
				break;
				}
			case 2:{
				cin.ignore(1,'\n');
                                string tempSearchName;
                                cout << "Enter name to search: ";
                                getline(cin, tempSearchName);
				FullList.search(tempSearchName);
				break;
				}
			case 3:{
				FullList.printAll();
				break;
				}
			case 4:{
				FullList.deleteAll();
			        cout << "you nuked the world!!\n";
				break;
				}
			case 5:{
				cin.ignore(1,'\n');
                                string tempSearchName;
                                cout << "Enter name to search: ";
                                getline(cin, tempSearchName);
                                FullList.remove(tempSearchName);
                                break;
				}
			default:{
				cout << "how did you get here? youre not supposed to do that" << endl;
				}
		}//end switch


	}while(choice != 0);

	return 0;
}

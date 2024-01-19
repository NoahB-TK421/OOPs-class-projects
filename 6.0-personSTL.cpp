/**************
Reuse your code from 5.0, so you will have 3 classes (person, student, faculty).

Instead of using the "list" class from 5.0, you will use an STL for a list. It just of LIST type to get full credit (not deque or vector or any of those).
 You will populate an STL structure with a series of objects (at least 5 combined). You will need to make a list of POINTERS to objects, in order to use polymorphism.

All faculty should be in the beginning of the list (add to the head), and students/interns should be at the end of the list (add at the tail). You don't need to add the base class objects at all.

You should use the STL functions to implement: add student/intern/faculty, remove a specific entry based on user input of a name, search for name, print all, and delete all.

Main will have your menu items and call the STL functions.

You will need to read and understand the documentation for the library and report any site you use (cite in the documentation and/or code comments). Submissions without citations will be penalized.

Fully test, document, and analyze the code.
*******************/


#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <list>
//#include <iterator>
//#include <algorithm>

using namespace std;

struct date{
		int month;
		int year;
};

class person{
		public:
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
};

date dateOfGraduation = {4,2002};


class student :public person{
		private: int a,b;
		public:
			date graduationDate;
//			date dateOfGraduation = {4,2002};
			string minor;
			student(){ fillIn();}
			student(string tempName, string tempDDM, int tempGradMonth, int tempGradYear, string tempMinor ):person(tempName,tempDDM){
				 setGradDate(tempGradMonth, tempGradYear); setMinor(tempMinor);}
			void print(){this->person::print(); cout << "Graduation date:"; getDate(); cout  << endl << "Minor:" << minor << endl;}

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
};

class facalty :public person{
		private: int a,b;
		public:
			date startDate;
			string title;
			facalty(){ fillIn();}
			facalty(string tempName, string tempDDM, int tempMonth, int tempYear, string tempTitle):person(tempName,tempDDM){ setStartDate(tempMonth,tempYear); setTitle(tempTitle);}
			void print(){this->person::print(); cout << "Start date:"; getDate(); cout << endl << "Title:" << title << endl;}
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
};

class intern :public student{

		public:
			double salary;
			string company;
			intern(){  fillIn();}
			intern(string tempName, string tempDDM, int tempMonth, int tempYear, string tempMinor, int tempSalary, string tempCompany ):student(tempName,tempDDM,tempMonth,tempYear,tempMinor){
				 setSalary(tempSalary); setCompany(tempCompany);}
			void print(){this->student::print(); cout << "salary:" << salary << endl << "Company:" << company << endl;}
			void setSalary(int tempSalary){ salary = tempSalary;}
			void setCompany(string tempCompany){company = tempCompany;}
			double getSalary(){return salary;}
			string getCompany(){return company;}

			void fillIn(){

//			        this->student::fillIn();
				cout << "\nEnter salary:";
				cin >> salary;

				cout << "\nEnter Company Name:";
				cin.ignore();
				getline(cin, company);
			}//end fillIn for intern

			~intern(){cout << name << " didnt feel like it anymore" << endl;}
};


int main(){

list<person*> people;

	new person("Hector Crawford", "facilities"),
	people.push_back(new student("Steve Irwin", "Allegator studies", 4,1999,"Wholsomeness"));
	people.push_front(new facalty("Bruce Gyngell", "Philosophy", 10, 1999, "Professor"));
	people.push_back(new intern("Bud Tingwell", "Film Studies", 7, 1993, "Acting", 20, "Good Movies inc."));

int choice;
do{
	cout << "would you like to:\n1: add student/facalty/intern\n2: search\n3: print all\n4:delete all" << endl;
	cin >> choice;

		switch(choice){
			case 1:{
				int choice1;
				cout <<"would you like to add a:\n1: student\n2:facalty\n3:intern\n";
				cin >> choice1;
			switch(choice1){
				case 1:{
					people.push_back(new student());
					break;
					}
				case 2:{
					people.push_front(new facalty());
					break;
					}
				case 3:{
					people.push_back(new intern());
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

                                for(list<person*>::iterator me = people.begin(); me != people.end(); me++){
					if((*me)->getName() == tempSearchName){

					(*me)->print();

						 int choice2;
			                         cout << endl <<"would you like to delete " << (*me)->getName() << "?\n1: yes\n2: no\n";
                        			 cin >> choice2;
				                 switch(choice2){
                                			case 1:{
                                        			me = people.erase(me);
								cout << "deleted\n";
                                       				break;
                                        		}
                                			case 2:{
			                                        cout << "not deleted\n";
                        			                break;
                                        			}
							default:{
								cout << "hot did you get here? Youre not supposed to do that\n";
								}
						}//end switch


					}else{
					cout << tempSearchName << " not found\n";
					}
					cout << endl;
				}

				break;
				}
			case 3:{
				for(list<person*>::iterator it = people.begin(); it != people.end(); ++it){

        			(*it)->print();
				cout << endl;

				}
				break;
				}
			case 4:{
				people.clear();
			        cout << "you nuked the world!!\n";
				break;
				}
			default:{
				cout << "how did you get here? youre not supposed to do that" << endl;
				}
		}//end switch
		}while(choice != 0);
people.clear(); 
return 0;
}//end main


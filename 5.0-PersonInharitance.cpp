/********
Create base and derived classes, instantiate objects, and test.
Base class: “Person” at Wentworth
	
	Attributes: Name, division/department/major
	Methods: 
		- Print all attributes
		- Constructors/destructor
		- Get functions (can skip set functions if you use the constructors properly)

Derived class: “Student”

	Attributes (beyond inherited ones from Person): Graduation date (month and year - as a struct), minor 
		
	Methods (beyond inherited ones from Person):
		- Set/get for all of the above
		- Calculate time to graduation (based on hard-coded current date) – just months/years
		- Print all student attributes (including inherited ones)
		- Constructor (with input parameters) – make sure to properly call person constructor
		- Destructor

Derived class: "Faculty"

	Attributes (beyond inherited ones from Person): start date (re-use the struct for date), title

	Methods (beyond inherited ones from Person):
		- Set/get for all of the above
		- Print all faculty attributes (including inherited ones)
		- Constructor (with input parameters) – make sure to properly call Student constructor
		- Destructor
		
Derived class: "Intern" based Derived from "Student"

	Attributes: company, salary
	
	Methods (in addition to others):
		- set/get/constructor/destructor/print

Note that a faculty and student should each be derived from the person class and Intern is based on student.

1) Create the class and instantiate one of each type of object and show the use of the functions through main. You may hardcode the object input arguments for all of the classes for this part. 

2) Create an array with each type using new.  Create a pointer that is used to traverse and print the list (you should have an array of pointers to objects, not an array of objects).  This will 
require polymorphism.  Test it by ensuring the base/derived functions are used properly.  
********/


#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct date{
		int month;
		int year;
};

class person{
		public:
			string name, ddm;
			person(){ setName(""); setDDM("");}
			person(string tempName, string tempDDM){ setName(tempName); setDDM(tempDDM);}
			virtual void print(){cout << "Name: " << name << endl << "division:" << ddm << endl;}
			void setName(string tempName){ name = tempName;}
			void setDDM(string tempDDM){ddm = tempDDM;}
			string getDDM(){return ddm;}
			string getName(){return name;}
			~person(){cout << name << " went to the store and didnt come back." << endl;}
};
date dateOfGraduation = {4,2002};
class student :public person{

		public:
			date graduationDate;
//			date dateOfGraduation = {4,2002};
			string minor;
			student(){  setName(""); setDDM(""); setGradDate(0,0); setMinor("");}
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
			~student(){cout << name << " decided to drop out." << endl;}
};

class facalty :public person{

		public:
			date startDate;
			string title;
			facalty(){ setName(""); setDDM(""); setStartDate(0,0); setTitle("");}
			facalty(string tempName, string tempDDM, int tempMonth, int tempYear, string tempTitle):person(tempName,tempDDM){ setStartDate(tempMonth,tempYear); setTitle(tempTitle);}
			void print(){this->person::print(); cout << "Start date:"; getDate(); cout << endl << "Title:" << title << endl;}
			void  setStartDate(int tempMonth, int tempYear){startDate.month = tempMonth; startDate.year = tempYear;}
			void setTitle(string tempTitle){title = tempTitle;}
			void getDate(){cout << startDate.month << "-" <<startDate.year;}
			string getTitle(){return title;}
			~facalty(){cout << name << " got sick of their students shit." << endl;}
};

class intern :public student{

		public:
			double salary;
			string company;
			intern(){  setName(""); setDDM(""); setGradDate(0,0); setMinor(""); setSalary(0); setCompany("");}
			intern(string tempName, string tempDDM, int tempMonth, int tempYear, string tempMinor, int tempSalary, string tempCompany ):student(tempName,tempDDM,tempMonth,tempYear,tempMinor){
				 setSalary(tempSalary); setCompany(tempCompany);}
			void print(){this->student::print(); cout << "salary:" << salary << endl << "Company:" << company << endl;}
			void setSalary(int tempSalary){ salary = tempSalary;}
			void setCompany(string tempCompany){company = tempCompany;}
			double getSalary(){return salary;}
			string getCompany(){return company;}
			~intern(){cout << name << " didnt feel like it anymore" << endl;}
};

int main(){
person *people[4] = {
	new person("Hector Crawford", "facilities"),
	new student("Steve Irwin", "Allegator studies", 4,1999,"Wholsomeness"),
	new facalty("Bruce Gyngell", "Philosophy", 10, 1999, "Professor"),
	new intern("Bud Tingwell", "Film Studies", 7, 1993, "Acting", 20, "Good Movies inc.")
	};
	
	for(int i = 0; i<4; i++){
		people[i]->print();
		cout << endl;
	}
return 0;
}

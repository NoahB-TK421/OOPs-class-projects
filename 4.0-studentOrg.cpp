/***********
Create a class for student organizations on campus. It should have a name, a faculty advisor, a budget, and the number of students. You must have an empty constructor and one with parameters. Use the 
initialization list for the constructor.  Get/set are only required for the numberOfStudents.

Create a friend function that compares two organizations and says which one has the higher budget per member.

The main should have at least 2 objects (and should be real organizations on campus).
***********/
#include <iostream>
using namespace std;
class studentOrg_c{
	private:
		string advisor, name;
		int budget, numberOfMembers;
	public:
		// create get/set for numberOfMembers (no need for others)

		studentOrg_c(){/* Fill this in */

			advisor = "N/A";
			name = "N/A";
			budget = 0;
			numberOfMembers = 0;
			cout << "Blank organization created" <<endl;
		}
		studentOrg_c(string a, string n, int b, int numMem){
			advisor = a;
			name = n;
			budget = b;
			numberOfMembers = numMem;
			cout << "Organization has been made" << endl;
		}
		~studentOrg_c(){
			cout << "Organization has been destroyed" << endl;
		}
		void setNumOfMembers(int num){
		numberOfMembers = num;
		}
		double getNumOfMembers(){
			return numberOfMembers;
		}
		friend void comparison(studentOrg_c &org1, studentOrg_c &org2 );

};

int main(){

	studentOrg_c organizationA( "Professor Carpenter", "IEEE", 100000, 30 );
	// make another organization object
	studentOrg_c organizationB("Professor Roberts", "ASME", 500, 6);
	comparison(organizationA, organizationB);
	
	// add 15 members to one organization using set function
	// compare again
	organizationB.setNumOfMembers(45);
	comparison(organizationA,organizationB);
	return 0;
}

// friend function definition here

void comparison(studentOrg_c &org1, studentOrg_c &org2){
	double budpermem1 = org1.budget/org1.getNumOfMembers();
	double budpermem2 = org1.budget/org2.getNumOfMembers();
	if(budpermem1 < budpermem2){
		cout << org1.name << " has a larger budget per member" << endl;
	}
	else if(budpermem2 < budpermem1){
		cout << org2.name << " has a larger budget per member" <<endl;
	}
	else{
		cout << org2.name << " and " << org1.name << " are equal" << endl;
	}
}

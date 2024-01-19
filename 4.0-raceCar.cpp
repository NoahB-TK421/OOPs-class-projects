#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;

class car_c{
	private:
		string driver;
		double number, fastLap, totTime;
		int bumps;
	public:
		car_c(){cout << "blank car created" << endl; }
		car_c(string d, double n){

			number = n;
			driver = d;
			fastLap =0;
			totTime = 0;
			bumps = 2;
			cout <<endl << "car created" << endl << "driver:" << d << endl << "number:" << n << endl << "fastest lap time:" << fastLap << endl<< "total time:" << totTime << endl<< "bumps:" << bumps<< endl;
		}
		~car_c(){cout << "car wrecked" <<endl;}
		void setTotTime(double f){totTime += f; }
		double generateLapSpeed(){
			int previous = fastLap;
			int next;
			next = rand() % 20+50;
			if(previous < next){ fastLap = next;}
			return next; 
		}
		void setBump(){bumps--;}
		double getFastLap(){return fastLap;}
		int getBump(){return bumps;}
		string getDriver(){return driver;}
		double getNumber(){return number;}
		double getTotTime(){return totTime;}
		friend void bump(car_c &car1, car_c &car2);
		friend void printDude(car_c &car1, car_c &car2);
};//end class

int main(){
car_c carA("Ricky Bobby", 26);
car_c carB("Cal Naughton Jr.", 47);
for(int i = 0; i <10;i++){
int bumpy =0;
int bumped = 0;

srand(carA.getBump()*carB.getNumber()+i*1776);
//if(carA.getBump() == 0 && carB.getBump() == 0){ys++;}
//if(carA.getBoost() ==0 && carB.getBoost() == 0){mmhmm++;}

	carA.setTotTime(carA.generateLapSpeed());

	carB.setTotTime(carB.generateLapSpeed());

while(bumped==0 && (carA.getBump() > 0 || carB.getBump() > 0)){
	cout <<endl << "who wants to bump whom?"<< endl << "1:" << carA.getDriver() << " bumps " << carB.getDriver() << endl << "2:" << carB.getDriver() << " bumps " << carA.getDriver()<< endl << "0 to skip" << endl<< "3: for both" << endl;
	cin >> bumpy;

		switch(bumpy){
			case 1:{
				if(carA.getBump() > 0){
					bump(carA,carB);
					bumped++;
				}else{
			        	cout << "not enough bumps left" << endl;
        			}
				break;
				}
			case 2:{
				if(carB.getBump() > 0){
                                	bump(carB,carA);
                                	bumped++;
                                }else{
                                	cout << "not enough bumps left" << endl;
                                }
				break;
				}
			case 0:{
				cout << "nobody bumped" << endl;
				bumped++;
				break;
				}
			case 3:{
				cout << "bumped each other" << endl;
				bump(carA, carB);
				bump(carB, carA);
				bumped++;
				}
			default:{
				cout << "how did you get here? youre not supposed to do that" << endl;
				}
		}//end switch
}//end while


}//end for

printDude(carA,carB);
}//end main


void bump(car_c &car1, car_c &car2){
	cout << car1.getDriver() << " bumped " << car2.getDriver()<< endl;
	car1.setTotTime(-1);
	car1.setBump();
	car2.setTotTime(-3);
}

void printDude(car_c &car1, car_c &car2){
	cout<< endl << "driver:" << car1.getDriver() << endl << "number:" << car1.getNumber() << endl << "total time:" << car1.getTotTime()<< endl<<"Fastest time:" << car1.getFastLap() <<endl;
	cout << endl << "driver:" << car2.getDriver() << endl << "number:" << car2.getNumber() << endl << "total time:" << car2.getTotTime()<< endl<<"Fastest time:"  << car2.getFastLap()<< endl;
	if(car1.getTotTime() >car2.getTotTime()){
		cout<< endl << car1.getDriver() << " wins!!!!!" << endl;
	}else if(car1.getTotTime() < car2.getTotTime()){
		cout<< endl << car2.getDriver() << " wins!!!!" << endl;
	}else{
		cout << endl<< "everybody wins!!!"<<endl;
	}
}


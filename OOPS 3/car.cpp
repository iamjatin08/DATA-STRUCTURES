#include"vehicle.h"


class car :virtual  public vehicle{
public:
	int numGears;
	// car(){
	// 	cout<<"default car constructor called"<<endl;
	// }

	// // car(int x,int y) : vehicle(x){
	// // 	cout<<"car constructor called"<<endl;
	// // 	numGears = y;
	// // }
	// ~car(){
	// 	cout<<"car distructor called"<<endl;
	// }
	void print(){
		// cout<<"NUM TYRES: "<<numTyres<<endl;
		// cout<<"color: "<<color<<endl;
		// cout<<"Num Gears: "<<numGears<<endl;
		// // cout<<"maxspeec: "<<maxSpeed<<endl;
		cout<<"car"<<endl;
	}

};
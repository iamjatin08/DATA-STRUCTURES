#include<iostream>
#include"car.cpp"
// #include"hondacity.cpp" 
#include"truck.cpp"
#include"bus.cpp"


using namespace std;


int main(int argc, char const *argv[])
{



	car c;
	vehicle v;
	vehicle *v1 = new vehicle;
	vehicle *v2;
	v2 = &c;
	v2->print();
	// v.print();
	
	// c.print();



	// Bus b;



	// HondaCity h(4,5);
	// // vehicle v;
	// // v.color = "BLUE";
	// // // v.maxSpeed = 100;
	// // // v.numTyres = 4;

	
	// car c(5);
	// c.color = "BLACK";
	// // c.numTyres = 4;
	// c.numGears = 5;

	return 0;
}
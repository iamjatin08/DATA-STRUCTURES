#include <iostream>
using namespace std;


#include "DynamicArray.cpp"

int main(int argc, char const *argv[])
{
	DynamicArray d1;
	d1.add(10);
	d1.add(20);
	d1.add(30);
	d1.add(40);
	d1.add(50);
	d1.getcapacity();
	d1.size();
	d1.add(60);
	
	d1.getcapacity();
	d1.size();
	d1.print();
	DynamicArray d2(d1);
	DynamicArray d3;
	d3 = d1;

	// d2.print();
	d1.add(0,100);
	d2.print();
	d3.print();
	return 0;

}
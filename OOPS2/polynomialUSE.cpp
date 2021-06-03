#include <iostream>
using namespace std;
#include "polynomial.cpp"


int main(int argc, char const *argv[])
{
	polynomial p1;
	for(int i = 0 ; i<5 ; i++){
		p1.set(i,i);
	}
	polynomial p2;
	p2 = p1;
	p2.set(3,5);
	p2.print();

	// polynomial p4(p1);
	// p4.print();
	p1.print();
	polynomial p3 = p1+p2;
	p3.print();
	return 0;
}
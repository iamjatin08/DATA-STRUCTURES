#include <iostream>
using namespace std;
#include "complex.cpp"


int main(int argc, char const *argv[])
{
	int real1,imaginary1,real2,imaginary2;
	cout<<"enter 1st complex number ";
	cin>>real1>>imaginary1;
	cout<<"enter 2nd complex number ";
	cin>>real2>>imaginary2;
	complexNumber c1(real1,imaginary1) ,c2(real2,imaginary2);
	cout<<"enter your choice ";
	int choice;
	cin>>choice;
	if(choice==1) {
		c1.plus(c2);
		c1.print();
	}
	else if(choice ==2){
		c1.multiply(c2);
		c1.print();
	}
	else {
		return 0;
	}
	
}
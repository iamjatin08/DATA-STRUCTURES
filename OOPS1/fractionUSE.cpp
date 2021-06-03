#include <iostream>
using namespace std;
#include "fractionClass.cpp"


int main(int argc, char const *argv[])
{

	// int i= 5;
	// int j = 3;
	// (i+=j)+=j;
	// cout<<i<<" "<<j<<endl;

	fraction f1(10,3);
	fraction f2(5,2);

	(f1+=f2)+=f2;
	f1.print();
	f2.print();

	// fraction f3 = f1++;
	// f1.print();
	// f3.print();

	// f1.print();
	// ++f1;
	// fraction f3 = ++f1;
	// f1.print();
	// ++(++f1);
	// f1.print();
	// fraction f3 = ++(++f1);
	// f1.print();
	// f3.print(); 
	// f3.print();










	// fraction f3 = f1+f2;
	// fraction f4 = f2+f3;
	// f1.print();
	// f2.print();
	// f3.print();
	// f4.print();
	// fraction f5 = f3*f4;
	// f5.print();
	// if(f1==f2){
	// 	cout<<"equal"<<endl;
	// }
	// else{
	// 	cout<<"not equal"<<endl;
	// }
	// cout<<(f3==f4)<<endl;
	// f1.print();
	
	// fraction const f3;
	// cout<<f3.getnumerator()<<endl;
	// cout<<f3.getdenominator()<<endl;
	// cout<<f1.getdenominator()<<endl;
	// f2.setnumerator(10);
	// f1.add(f2);
	
	// f1.print();
	// f2.print();
	// f1.multiply(f2);
	// f1.print();
	// f2.print();
	return 0;
}
#include<iostream>
using namespace std;
#include "student.cpp"

int main(int argc, char const *argv[])
{
	// student s1(10,1001);
	// cout<<"adress of s1 : "<<&s1<<endl;

	string s = "a";
	string s1 = to_string(2)+s;
	cout<<s1<<endl;
	// student s1;
	// s1.display();
	// cout<<endl;
	// student s2;

	// student *s3 = new student ;
	// s3->display();
	// cout<<endl;
	// cout<<"paramaterized constructor"<<endl;
	// student s4(14);
	// s4.display();
	// cout<<endl;
	// student  * s5 = new student(101) ;
	// student s6(10,15);
	// s6.display();
	// cout<<endl;

	return 0;
}
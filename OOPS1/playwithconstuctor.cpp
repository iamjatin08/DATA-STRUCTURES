#include<iostream>
using namespace std;
#include "student.cpp"


int main(int argc, char const *argv[])
{
	student s1; //constructor 1 called
	student s2(101); // constructor 2 called
	student s3(20,102); //constructor 3 called

	student s4(s3); //copy constructor called
	s1 = s2;  // copy asignment operator

	student s5 = s4; // copy constructor called




	return 0;
}
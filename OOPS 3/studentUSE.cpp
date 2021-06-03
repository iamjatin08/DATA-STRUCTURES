#include <iostream>
using namespace std;
#include"student.cpp"
#include"teacher.cpp"
#include"TA.cpp"


int main(int argc, char const *argv[])
{
	TA a;
	// a.student :: print();

	a.print();
	a.teacher :: name = "abcd";
	cout<<a.teacher::name<<endl;
	return 0;
}
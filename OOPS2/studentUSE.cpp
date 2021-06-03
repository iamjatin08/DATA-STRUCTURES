#include <iostream>
using namespace std;
#include "student.cpp"

int main(int argc, char const *argv[])
{

	char name[] = "abcd";
	student  s1(20,name);
	s1.display();
	student s2(s1);
	s2.name[0] = 'x';
	s2.display();
	s1.display();


	// student s1(20,name);
	// s1.display();
	// name[3]='e';
	// student s2(24,name);
	// s2.display();
	// s1.display();
	return 0;
}
#include <iostream>
using namespace std;
#include "student.cpp"



int main(int argc, char const *argv[])
{
	student  s1 ;
	student *s2 = new student;

	s1.setAge(20,123);
	s1.rollNumber = 104;

	s2->setAge(30,123);
	s2->rollNumber = 105;
	s1.display();
	cout<<endl;
	s2->display(); 
	cout<<endl;
	s2->display();
	cout<<endl;
	


	return 0;
}
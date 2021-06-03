#include<iostream>
using namespace std;
#include "student.cpp"

int main(){
student s1;
student s2;
student s3 ,s4,s5 ;
// create object dynamically
student *s6 = new student;
// s1.age = 24;
s1.rollNumber = 101;
cout<<s1.getAge()<<endl;
cout<<s1.rollNumber<<endl;
// (*s6).age = 23;
(*s6).rollNumber = 104;
// s6->age  = 23;
s6->rollNumber = 104;

s1.display();
cout<<endl;
s6->display();
cout<<endl;


// cout<<(*s6).age<<endl;
cout<<s6->getAge()<<endl;
}
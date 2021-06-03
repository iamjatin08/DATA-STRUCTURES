#include <iostream>
using namespace std;
int a;

void g(){
a++;
cout<<a<<endl;
}

void f(){
cout<<a<<endl;
a++;
cout<<a<<endl;
}


int  main(int argc, char const *argv[])
{
	a = 10;
	// cout<<a<<endl;
	f();
	// g();
	f();
	return 0;
}
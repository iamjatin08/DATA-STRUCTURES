#include <iostream>
using namespace std;


void print(int *p ){
	cout<<*p<<endl;
}
void incrementpointer(int *p){
	p=p+1; 
}
void increment(int *p){
	(*p)++;
}


int main(int argc, char const *argv[])
{
	int i = 10;
	int *p = &i;
	print(p);
	cout<<p<<endl;
	incrementpointer(p);
	cout<<p<<endl;
	cout<<*p<<endl;
	increment(p);
	cout<<*p<<endl;


	return 0;
}
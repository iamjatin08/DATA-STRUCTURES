#include <iostream>
using namespace std;

void increment(int & n) {
	n++;
}

//bad practice
int& f(int n){
	int a  = n;
	return a;
}
//practice
int* f2(){
	int i = 10;
return &i;
}
int main(int argc, char const *argv[])
{
	int *p  = f2();
	cout<<p<<endl;
	int i = 10;
	int& j = i; 
	i++;
	
	j++;
	int &K = f(i);
	cout<<K<<endl;
	increment(j);

	cout<<j<<endl;
	cout<<i<<endl;


	int k = 100;
	j = k;

	
	cout<<i<<endl;
	cout<<j<<endl;
	
	return 0;
}
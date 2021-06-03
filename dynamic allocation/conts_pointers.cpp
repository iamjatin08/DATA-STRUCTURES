#include <iostream>
using namespace std;

void g(int const &a){
	// a++;
}

int f(const int *p){
	// return (*p)++;
	return 0;
}

int main(int argc, char const *argv[])
{
	int const i= 10;
	int const *p = &i;
	cout<<p<<endl;
	


	int j = 12;
	int const *p2 = &j;
	// p2++;
	cout<<*p2<<endl;
	j++;
	cout<<*p2<<endl;


	return 0;
}
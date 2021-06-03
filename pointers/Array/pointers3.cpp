#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	int i ;
	cout<<i<<endl;
	i++;
	cout<<i<<endl;
	int *p = 0;
	cout<<p<<endl;

	cout<<*p<<endl;
	(*p)++;
	cout<<*p<<endl;
	return 0;
}
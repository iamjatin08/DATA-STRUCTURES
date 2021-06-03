#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	int i = 10;
	int *p = &i;
	cout<<sizeof(p)<<endl;
	cout<<i<<endl;
	cout<<*p<<endl;
	i++;
	cout<<i<<endl;
	cout<<*p<<endl;

	int a = i;
	a++;
	cout<<a<<endl;
	cout<<i<<endl;

	return 0;
}
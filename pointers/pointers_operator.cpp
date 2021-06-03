#include <iostream>
using namespace std;



int main(int argc, char const *argv[])
{
	int i = 10;
	int * p = &i;
	cout<<p<<endl;
	cout<<*p<<endl;
	p++;
	cout<<p<<endl;
	cout<<*p<<endl;
	p-=2;
	cout<<p<<endl;
	cout<<*p<<endl;
	 
	double d= 102.2;
	double *dp = &d;
	cout<<dp<<endl;
	dp++;
	cout<<dp<<endl;
	return 0;
}
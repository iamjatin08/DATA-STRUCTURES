#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	const int i  = 10;
	cout<<i<<endl;
	int j = 12;
	const int &k = j;
	// k++; 
	j++;
	// int &m = i; 
	cout<<k<<endl;
	int const j2 = 12;
	int const &k2 = j2;
	// k2++;
	// j2++;

	cout<<j<<endl; 

	int const j3 = 123;
	int & k3 = j3;
	// k++;
	return 0;
}
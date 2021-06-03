#include <iostream>
using namespace std;

inline int max(int a,  int b){
	return (a>b)?a:b;
}

int main(int argc, char const *argv[])
{
	int a , b;
	cin>>a>>b;
	a = 3;
	b = 5;
	int c = (a>b)?a:b;
	cout<<c<<endl;
	int x= 12;
	int y = 34;
	int z = max(x,y);
	cout<<z<<endl;

	return 0; 
}
#include<iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	int *p = new int;
	*p = 10;
	cout<<*p<<endl;

	// double*pd = new double;
	char *c = new char;

	int * pd = new int[50];
	int n;
	cout<<"enter size of array"<<endl;
	cin>>n;
	int *pa2 = new int[n];
	cout<<"enter num of elements"<<endl;
	int ans  = -1;
	for(int i = 0 ; i<n ; i++){
		cin>>pa2[i];
		
	}
	
	for(int i = 0; i<n ; i++){
		ans  = max(ans, pa2[i]);
	}
	cout<<"max element is "<<ans<<endl;

	return 0;
}
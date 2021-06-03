#include<iostream>
using namespace std;

long long factorial(int n){
	if(n==0) return 1;
	return n*factorial(n-1);
}


int main(){
	int n = 5;
	cin>>n;
	long long  output = factorial(n);
	cout<<output<<endl;


	return 0;
}
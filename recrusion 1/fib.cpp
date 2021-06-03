#include<iostream>
using namespace std;

int fib(int n){
	if(n == 0 or n == 1) return n;
	int smalloutput1 = fib(n-1);
	int smalloutput2 = fib(n-2);
	return smalloutput2 + smalloutput1;
}

int fib2(int n){
	if(n == 0 or n == 1) return n;
	return fib2(n-1)+fib(n-2);
}

int main(){
	
	int n;
	n = 6; 
	cout<<fib2(n)<<endl;


	return 0;
}
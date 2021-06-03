#include<iostream>
using namespace std;
#include "stack_ARRAY.cpp"

 
int main(int argc, char const *argv[])
{
	stackusingArray<char> s;
	for(int i = 1 ; i<=26 ; i++){
		s.push(96+i);
	} 
	while(!s.isEmpty()){
		cout<<s.top()<<endl;
		s.pop(); 
	}
		
		return 0;
}
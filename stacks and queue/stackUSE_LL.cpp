#include <iostream>
using namespace std;
#include "stackUsingLL.cpp"



int main(int argc, char const *argv[])
{
	Stack<int> s;
	for(int i  = 1 ; i<=100 ;i++){
		s.push(i);
	}
	cout<<"SIZE : "<<s.getsize()<<endl;
	while(!s.isEmpty()){
		cout<<s.pop()<<endl;
	}
	cout<<"SIZE : "<<s.getsize()<<endl;
	
	return 0;
}
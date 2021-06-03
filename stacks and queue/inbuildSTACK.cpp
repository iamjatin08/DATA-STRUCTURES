#include<iostream>
#include<stack>
using namespace std;


int main(int argc, char const *argv[])
{
	// fuction names are .size() ,.pop(),.push()
	stack<int> s;
	for(int i = 0 ; i<=20;i++){
		s.push(i*10);
	}
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}
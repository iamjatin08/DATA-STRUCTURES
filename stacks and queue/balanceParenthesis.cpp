#include<iostream>
#include<stack>
using namespace std;

bool balance(string s){
	stack<char> a;
	for(int i = 0 ; i<s.size();i++){
		if(s[i]=='(' || s[i] =='{' || s[i]=='[') a.push(s[i]);
		if(s[i]=='}' or a.empty()){
			if(!a.empty() and a.top()=='{') a.pop();
			else return false;
		}
		if(s[i]==']'){
			if(a.top()=='[') a.pop();
			else return false;
		}
		if(s[i]==')' ){
			if(a.top()=='(') a.pop();
			else return false;
		}
	}


	return a.empty();

}


int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	if(balance(s)){
		cout<<"BALANCED"<<endl;
	}
	else{
		cout<<"NOT BALANCED"<<endl;
	}
	return 0;
}
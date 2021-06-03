#include<iostream>
#include<string>
using namespace std;
string s[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printKEYPAD(int n , string output = ""){
	if(n==0){
		cout<<output<<endl;
		return ;
	}
	int index = n%10;
	for(int i = 0 ; i<s[index].size() ;i++){
		char ch = s[index][i];
		printKEYPAD(n/10,output+ch);
	}

}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	printKEYPAD(n);
	return 0;
}
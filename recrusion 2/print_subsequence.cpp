#include<iostream>
using namespace std;

void printsubseq(string input , string output = ""){
	if(input.empty()) {
		cout<<output<<endl;
		return;
	}
	char ch = input[0];
	printsubseq(input.substr(1) ,output);
	printsubseq(input.substr(1) ,output+ch);
}




int main(int argc, char const *argv[])
{
	string input;
	cin>>input;
	printsubseq(input);
	return 0;
}
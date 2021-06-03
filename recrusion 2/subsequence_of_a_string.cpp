#include<iostream>
#include<string>
#include<math.h>
using namespace std;



int subsequence(string input , string output[]){
	if(input.empty()){
		output[0] = "";
		return 1;
	} 
	
	string small_string  = input.substr(1);
	int smallOutputSize = subsequence(small_string ,output);
	for(int i = 0 ; i<smallOutputSize ;i++){
		output[i + smallOutputSize] = input[0] + output[i];
	}
	return 2*smallOutputSize;
}


int main(int argc, char const *argv[])
{
	string input;
	cin>>input;
	int n  = pow( 2 ,input.size());

	string *output = new string[n];
	int count = subsequence(input,output);
	for(int i = n-1; i>=0 ;i--){
		cout<<output[i]<<endl;
	}
	
	return 0;
}
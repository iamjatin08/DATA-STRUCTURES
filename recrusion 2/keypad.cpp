#include<iostream>
#include<string>
#include<math.h>
using namespace std;

string s[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int n ,string output[]){
	if(n==0){
		output[0] = "" ;
		return 1;
	}
	int index = n%10;
	int smallOutputSize = keypad(n/10,output);
	int count = smallOutputSize;
	int number = count*s[index].size();
	for(int i  = 1 ; i<s[index].size() ; i++){
		for(int j = 0 ; j<smallOutputSize ;j++){
			output[count] = output[j] + s[index][i];
			count++;
		}
	}
	for(int j = 0 ; j<smallOutputSize ;j++){
		output[j] = output[j] + s[index][0];
	}
	
	return number;

}



int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	
	string * output = new string[100];
	int count  = keypad(n,output);
	for(int i = 0;  i<count ; i++){
		cout<<output[i]<<endl;
	}
	return 0;
}
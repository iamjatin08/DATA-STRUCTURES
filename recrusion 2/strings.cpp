#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{

	string *sp = new string;
	*sp = "abcdef";
	string s = "abcd";
	cout<<s<<endl;
	cout<<sp<<endl;
	cout<<*sp<<endl;
	// getline(cin,s);
	 string s2 = "bdksnfk";
	string s3 = s + s2;
	cout<<s<<endl;
	cout<<s[0]<<endl;
	cout<<s3<<endl;
	cout<<s3.size()<<endl;
	cout<<s3.substr(2)<<endl;
	cout<<s3.find("nf")<<endl;
	return 0;
}
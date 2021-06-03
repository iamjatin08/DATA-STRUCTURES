#include<iostream>
#include "ourmap.h"
using namespace std;


int main(int argc, char const *argv[])
{
	ourmap<int> mp;
	for(int i = 0 ; i<10 ; i++){
		char c = '0' + i;
		string key = "abc";
		key = key + c;
		int value = i+ 1;
		mp.insert(key,value);
	}
	cout<<mp.size()<<endl;
	return 0;
}

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;


int main(int argc, char const *argv[])
{
	unordered_map<string,int> ourmap;
	
	ourmap["abc1"] = 1;
	ourmap["abc2"] = 2;
	ourmap["abc3"] = 3;
	ourmap["abc4"] = 4;
	ourmap["abc5"] = 5;
	ourmap["abc6"] = 6;
	ourmap["abc7"] = 7;
	
	unordered_map<string,int> :: iterator it;
	for(it = ourmap.begin() ; it!=ourmap.end() ; it++){
		cout<<"KEY: "<<it->first<<" "<<"VALUE: "<<it->second<<endl;
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it1 = v.begin();
	while(it1!=v.end()){
		cout<<*it1<<endl;

		it1++;
	}

	// find
	unordered_map<string,int>::iterator it2 = ourmap.find("abc1");
	ourmap.erase(it2);


	return 0;
}
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;




int main(int argc, char const *argv[])
{
	unordered_map<string,int> ourmap;

	//insert
	pair<string,int> p("abc",1);
	ourmap.insert(p);

	ourmap["def"] = 2;

	// find or access
	cout<<ourmap["abc"]<<endl;
	cout<<ourmap.at("abc")<<endl;

	cout<<ourmap.size()<<endl;
	cout<<ourmap["gfi"]<<endl;

	//size function
	cout<<ourmap.size()<<endl;

	//	check presence
	if(ourmap.count("ghi")>0){
		cout<<ourmap["ghi"]<<endl;
	}
	else{
		cout<<ourmap["abc"]<<endl;
	}

	//erase
	ourmap.erase("abc");
	cout<<ourmap.size()<<endl;
	return 0;
}
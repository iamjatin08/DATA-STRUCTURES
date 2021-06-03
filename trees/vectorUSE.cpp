#include<iostream>
#include<vector>
using namespace std;




int main(int argc, char const *argv[])
{
	// dynamic allocation
	// vector<int> * vp = new vector<int>();


	// static allocation
	vector<int> v;
	for(int i = 0  ; i<100 ; i++){
		cout<<"SIZE : "<<v.size()<<" CAPACITY : "<<v.capacity()<<endl;
		v.push_back(i+1);
		}

	// v.push_back(10);
	// v.push_back(20);
	// v.push_back(30);
	
	// v[1] = 100;
	// // dont use[] for inserting elements
	// v[3] = 1002;
	// v[4] = 1234;
	// v.push_back(23);
	// v.push_back(234);
	// // to remove last element
	// v.pop_back();

	// cout<<v[0]<<endl;
	// cout<<v[1]<<endl;
	// cout<<v[2]<<endl;
	// cout<<v[3]<<endl;
	// cout<<v[4]<<endl;
	// cout<<v[5]<<endl;
	// cout<<v[6]<<endl;
	
	// cout<<"SIZE : "<< v.size()<<endl;
	// // .at() is safe to use than []
	// cout<<v.at(2)<<endl;
	// for(int i = 0 ; i<v.size() ; i++)
	// 	cout<<v[i]<<endl;
	
	return 0;
}
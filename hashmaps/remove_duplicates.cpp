#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//my code
vector<int> removeduplicates(vector<int> v){

	unordered_map<int,bool> mp;
	vector<int> ans;
	for(int i = 0 ; i<v.size() ; i++){
		if(mp.count(v[i])>0) continue;
		else{
			mp[v[i]] = true;
			ans.push_back(v[i]);
		}
	}
	return ans;
}

// coding ninja code

vector<int> removeDup(int* a,int size){
	vector<int> output;
	unordered_map<int,bool> seen;
	for(int i = 0; i<size; i++){
		if(seen.count(a[i])>0) continue;
		seen[a[i]] = true;
		output.push_back(a[i]);
	}
	return output;
}


int main(int argc, char const *argv[])
{
	
	int a[] = {1,2,3,3,2,1,4,3,6,5,5};
	vector<int> ans = removeDup(a,11);
	for(int i  = 0 ; i<ans.size(); i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}
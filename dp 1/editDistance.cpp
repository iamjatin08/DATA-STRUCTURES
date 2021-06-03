#include<iostream>
using namespace std;



int editDistance(string s , string t){
	if(s.size()==0) return t.size();
	if(t.size() == 0) return s.size();
	if(s.size() == 0 and t.size() == 0) return 0;
	if(s[0]==t[0]){
		return editDistance(s.substr(1),t.substr(1));
	}
	//insert
	int a = editDistance(s.substr(1),t);
	//delete
	int b = editDistance(s,t.substr(1));
	//replace
	int c = editDistance(s.substr(1),t.substr(1));
	return 1+min(a,min(b,c));
}
int editDistancehelper(string s , string t, int** dp){
	if(s.size() == 0 or t.size() == 0){
		return max(s.size() ,t.size());
	}
	int m = s.size();
	int n = t.size();

	if(dp[m][n]!=(-1)) return dp[m][n];
	if(s[0] == t[0]) {
		dp[m][n] = editDistancehelper(s.substr(1),t.substr(1),dp);
		return dp[m-1][n-1];
	}
	else{
		dp[m-1][n] = editDistancehelper(s.substr(1),t,dp);
		dp[m][n-1] = editDistancehelper(s,t.substr(1),dp);
		dp[m-1][n-1] = editDistancehelper(s.substr(1),t.substr(1),dp);
		dp[m][n] = 1 + min(dp[m-1][n],min(dp[m-1][n-1],dp[m][n-1]));
	}
	
	return dp[m][n];
}
int editDistancebetter(string s, string t){
	int m = s.size();
	int n = t.size();
	int **dp = new int*[m+1];
	for(int i = 0 ; i<=m ; i++){
		for(int j = 0 ; j<=n ; j++){
			dp[i][j] = -1;
		}
	}
	int ans = editDistancehelper(s,t,dp);
	for(int i = 0 ; i<=m ; i++){
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}

int editDistance_DP(string s, string t){
	if(s.size() == 0 or t.size()) 
		return max(s.size(),t.size());
	int m = s.size();
	int n = t.size();
	int ans[m+1][n+1];
	for(int i = 0 ; i<=m ; i++){
		ans[i][0] = i;
	}
	for(int i = 0 ; i<= n ; i++){
		ans[0][i] = i;
	}
	for(int i = 1; i<=m ; i++){
		for(int j = 1 ; j<=n ;j++){
			if(s[m-i]==t[n-j]){
				ans[i][j] = ans[i-1][j-1];
			}
			else{
				ans[i][j] = 1+min(ans[i-1][j],min(ans[i-1][j-1],ans[i][j-1]));
			}
		}
	}
	return ans[m][n];
}

int main(){


	string s,t;
	cin>>s>>t;
	cout<<editDistance(s,t)<<endl;
	// cout<<editDistancebetter(s,t)<<endl;
	cout<<editDistance_DP(s,t)<<endl;

	return 0;
}
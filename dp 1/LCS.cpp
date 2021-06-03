#include<iostream>
#include<string>
using namespace std;



int LCS(string s , string t,int i , int j , int** dp){
	//base case
	if(s.size()==0 or t.size() == 0) return 0;

	if(dp[i][j]!=(-1)) return dp[i][j];

	if(s[0] == t[0]){
		dp[i][j] =  1+ LCS(s.substr(1),t.substr(1),i-1,j-1,dp);
		return dp[i][j];
	} 

	//recrusive calls 
	int a = LCS(s.substr(1),t,i-1,j,dp);
	int b = LCS(s,t.substr(1),i,j-1,dp);
	dp[i][j] = max(a,b);
	return dp[i][j];

}

int LCS(string s, string t){
	int** dp = new int*[s.size()+1];
	for(int i =  0 ; i<=s.size() ; i++){
		dp[i] = new int[t.size()+1];
		for(int j = 0 ; j<=t.size() ; j++){
			dp[i][j] = -1;
		}
	}
	int ans  = LCS(s,t,s.size(),t.size(),dp);
	delete [] dp;
	return ans;
}


int LCS_DP(string s , string t){
	int m  = s.size();
	int n = t.size();
	int dp[m+1][n+1];
	for(int i = 0 ; i<= m ; i++) dp[i][0] = 0;
	for(int i = 0 ; i<=m ; i++) dp[0][i] = 0;
	
	for(int i = 1 ; i<=m ; i++){
		for(int j = 1 ; j<=n ;j++){
			if(s[m-i] == t[n-j]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}	
	return dp[m][n];
}



int main(int argc, char const *argv[])
{
	
	string s,t;
	cin>>s>> t;
	cout<<LCS(s,t)<<endl;
	cout<<LCS_DP(s,t)<<endl;
	return 0;
}
#include <iostream>
#include<climits>
using namespace std;


int minsteps(int n,int* dp){
	if(n==1) return 0;
	if(dp[n]!=(0)) return dp[n];
	int a = INT_MAX;
	int b = INT_MAX;
	int c = INT_MAX;
	if(n%3==0){
		a = minsteps(n/3,dp);
	}
	if(n%2 == 0){
		b = minsteps(n/2,dp);
	}
	c = minsteps(n-1,dp);
	int ans  = min(a,min(b,c))+1;
	dp[n] = ans;
	return ans;
}

int minsteps(int n){
	int* dp = new int[n+1];
	for(int i = 0 ; i<=n ; i++) dp[n] = 0;
	int ans = minsteps(n,dp);
	delete [] dp;
	return ans;
}


int minstepsDP(int n){
	int dp[n+1];
	dp[0] = -1 ;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for(int i = 4 ; i<n+1 ; i++){
		int a = INT_MAX;
		int b = INT_MAX;
		int c = INT_MAX;
		if(i%3==0){
			a = dp[i/3];
		}
		if(i%2==0)
			b = dp[i/2];
		c = dp[i-1];
		int ans  = min(a,min(b,c))+1;
		dp[i] = ans;
	}
	return dp[n];
}


int main(int argc, char const *argv[])
{
	int n = 100;
	// int* dp = new int[n+1];
	// for(int i = 0 ; i<n+1 ; i++) dp[i] = 0;
	cout<<minstepsDP(n)<<endl;

	return 0;
}
#include<iostream>
#include<math.h>
using namespace std;


int balancedBTs(int h, int* dp){
	if(h<=1 ) return 1;
	if(dp[h]!=(-1)) return dp[h];
	int mod = pow(10,9)+7;
	int x = balancedBTs(h-1,dp);
	int y = balancedBTs(h-2,dp);

	int temp1 = (int)(((long)(x)*x)%mod);
	int temp2 = (int)((2*(long)(x)*y)%mod);
	int ans = (temp1 + temp2)%mod;
	dp[h] = ans;
	
	return ans;
}

int balancedBTs(int h){
	int *dp = new int[h+1];
	for(int i = 0 ; i<h+1 ;i++) dp[i] = -1;
	int ans = 	balancedBTs(h,dp);
	delete [] dp;
	return ans;
}
int balancedBTsDP(int h){
	int * dp = new int[h+1];
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2 ; i<h+1 ; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	int ans = dp[h];


	delete [] dp;
	return ans;
}


int main(int argc, char const *argv[])
{
	int h;
	cin>>h;
	cout<<balancedBTs(h)<<endl;
	return 0;
}
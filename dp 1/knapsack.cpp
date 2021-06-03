#include<iostream>
using namespace std;




int knapsack(int* weight,int *value, int n ,int maxweight,int* dp){
	// base case
	if(n==0 or maxweight ==0) return 0;
	if(dp[n]!=(-1)) return dp[n];
	if(weight[0]>maxweight){
		dp[n] = knapsack(weight+1,value+1,n-1,maxweight,dp);
	}
	// recrusive calls
	int x  = knapsack(weight+1,value+1,n-1,maxweight-weight[0],dp);
	int y = knapsack(weight+1,value+1,n-1,maxweight,dp);
	dp[n] =  max(x,y);
}


int knapsack(int* weight,int *value, int n ,int maxweight){
	int * dp = new int[n+1];
	for(int i = 0 ; i<n+1 ; i++) dp[i] = -1;
	int ans = knapsack(weight,value,n,maxweight,dp);
	delete [] dp;
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
#include<iostream>
using namespace std;


int fib(int n){
	if(n==0 or n == 1) return n;
	return fib(n-1) + fib(n-2);
}


int fibbymem(int n, int dp[]){
	if(n==0 or n==1) return n;
	if(dp[n]!=0) return dp[n];
	int ans =fibbymem(n-1,dp)+fibbymem(n-2,dp);
	return dp[n]= ans;
}

int purefib(int n ){
	double arr[n+1];
	arr[0] = 0 ;
	arr[1] = 1 ;
	for(int i = 2 ; i<=n ; i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
	return arr[n];
}


int fib0_better(int n , int * ans){
	if(n==0 or n == 1){
		return n;
	}
	if(ans[n-1]==0){
		ans[n-1] = fib0_better(n-1,ans);
	}
	if(ans[n-2]==0) ans[n-2] = fib0_better(n-2,ans);
	ans[n] = ans[n-1] + ans[n-2];
	return ans[n];
}

int fib0_better(int n){
	int *ans = new int[n+1];
	for(int i = 0 ; i<n;i++) ans[i] = 0;
	int answer  = fib0_better(n,ans);
	delete [] ans;
	return answer;	
}

int main(int argc, char const *argv[])
{
	int n;
	n = 5;
	
	cout<<purefib(10)<<endl;
	
	return 0;
}
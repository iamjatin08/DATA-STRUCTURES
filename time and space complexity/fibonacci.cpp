#include<iostream>
using namespace std;

int fib(int n){
	if(n==1 or n==0) return n;
	int answer = fib(n-1)+fib(n-2);
	return answer;
}

int dp[100] = {0};


int fibdp(int n , int *dp2){
	if(n==0 or n==1) return n;
	if(dp2[n]!=-1) return dp[n];
	dp2[n] = fibdp(n-1,dp2)+fibdp(n-2,dp2);
	return dp[n];
}


int fibdp2(int n){
	dp[0] = 0;
	dp[1] = 1;
	for(int i  = 0  ; i<=n ; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	return dp[n];

}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *dp2 = new int[n+1];
	for(int i = 0  ; i<=n ; i++){
		dp2[i] = -1;
	}
	cout<<fibdp(n , dp2)<<endl;
	cout<<fibdp2(n)<<endl;
	cout<<fib(n)<<endl;
	return 0;
}
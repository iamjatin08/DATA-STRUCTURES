#include<iostream>
#include<climits>
using namespace std;

int minCostPathDP(int **input, int m , int n){
	int ans[m][n];
	ans[m-1][n-1] = input[m-1][n-1];
	// last row
	for(int j = n-2 ; j>=0 ;j--){
		ans[m-1][j] = input[m-1][j] + ans[m-1][j+1];
	}
	for(int i = m-2 ; i>=0 ; i--){

		ans[i][n-1] = input[i][n-1] + ans [i+1][n-1];
	}

	for(int i = m-2; i>=0 ; i--){
		for(int j = n-2 ; j>=0 ; j--){
			ans[i][j] = input[i][j] + min(ans[i][j+1],min(ans[i+1][j+1],ans[i+1][j]));
		}
	}
	return ans[0][0];
}






int minCostPath(int** input,int sr,int er , int sc, int ec, int** dp){
	// base case
	if(sr>er or sc>ec) return INT_MAX ;
	if(sr==er and sc==er) return input[sr][sc];
	if(dp[sr][sc]!=(-1)) return dp[sr][sc];


	// recursive call;
	int a = minCostPath(input,sr+1,er,sc,ec,dp);
	if(a<INT_MAX){
		dp[sr+1][sc] = a;
	}
	int b = minCostPath(input,sr,er,sc+1,ec,dp);
	if(b<INT_MAX){
		dp[sr][sc+1] = b;
	}
	int c = minCostPath(input,sr+1,er,sc+1,ec,dp);
	if(c<INT_MAX){
		dp[sr+1][sc+1] = c;
	}
	int ans  = min(a,min(b,c)) + input[sr][sc];
	dp[sr][sc] = ans;

	return ans;


}


int minCostPath(int ** input,int m, int n){
	int ** dp = new int*[m+1];
	for(int i = 0 ; i<=m ; i++){
		dp[i] = new int[n+1];
		for(int j = 0 ; j<=n ; j++) dp[i][j] = -1;
	}
	int ans =  minCostPath(input,0,m-1,0,n-1,dp);
	for(int i = 0 ; i<=m ; i++){
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}



int main(int argc, char const *argv[])
{	
	int m , n;
	cin>>m>>n;
	int **input = new int*[m];
	for(int i = 0 ; i<m ; i++){
		input[i] = new int[n];
		for(int j = 0 ; j<m ; j++){
			cin>>input[i][j];
		}
	}


	cout<<minCostPath(input,m,n)<<endl;
	cout<<minCostPathDP(input,m,n)<<endl;
	for(int i = 0 ; i<m ; i++){
		delete [] input[i];
	}

	delete [] input;
	return 0;
}
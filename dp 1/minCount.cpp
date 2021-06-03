#include <bits/stdc++.h>
using namespace std;
 
int getMinSquares(int n)
{
    
    if(n<=3)
      return n;
     
    
    int* dp = new int[n + 1];
 
   
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
 
    
    for (int i = 4; i <= n; i++)
    {
         
        
        dp[i] = i;
 
        for (int x = 1; x <= i*i; x++)
        {
            int temp = x * x;
            if (temp > i)
                break;
            else
                dp[i] = min(dp[i], 1 +
                                  dp[i - temp]);
        }
    }
 	int res = dp[n];
    delete[] dp;
 	return res;
}


int minCount(int n, int* dp){
	if(n == 0) return 0;
	if(dp[n]!=(-1)) return dp[n];

	int ans = INT_MAX;

	for(int i = 1 ; (i*i)<=n ;i++){

		int temp = minCount(n - (i*i),dp);
		ans = min(ans,temp+1);


	}
	dp[n] = ans;
	return ans;


}


int minCount(int n){
	int* dp = new int[n+1];
	for(int i = 0 ; i<n+1 ; i++) dp[i] = -1;
	int ans  = minCount(n,dp);
	delete [] dp;
	return ans;
}

 

int main()
{
    cout << minCount(6)<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
	
	
	int fib(int n)
	{
      
      int dp[1000]={};
      dp[0]=0;
      dp[1]=1;

      for(int currnum=2;currnum<=n;currnum++)
      {
      	dp[currnum]=dp[currnum-1]+dp[currnum-2];
       }
       
      return dp[n];
	}

    int main()
  {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
     
     int n;
     cin>>n;
    
     int ans=fib(n);
     cout<<n<<"th fibo is "<<ans;
 }
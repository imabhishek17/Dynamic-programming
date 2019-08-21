#include<bits/stdc++.h>
using namespace std;
const int infy=(int)1e9;

int memo[10000];

int reduce_no(int n)                  //using memoization
{
	if(n==1)return 0;
	int q1=infy,q2=infy,q3=infy;

	if(memo[n]!=-1) return memo[n]; //because this has already been copied! No recomputation

	if(n%3==0) q1=1+reduce_no(n/3);
	if(n%2==0) q2=1+reduce_no(n/2);
	q3=1+reduce_no(n-1);

	memo[n]=min(q1,min(q2,q3));
	return memo[n];
}

int reduce_no_DP(int n)          //using pure dp
{
	int dp[10000];
	//setting the base cases
	dp[0]=0;  dp[1]=0;
	dp[2]=1; dp[3]=1;

	//compute the ans for n
	for(int currnum=4;currnum<=n;currnum++)
 {
		int q1=infy;
	    int q2=infy;
	    int q3=infy;

	    if(n%3==0) q1=1+reduce_no(n/3);
	   if(n%2==0) q2=1+reduce_no(n/2);
	   q3=1+reduce_no(n-1);
 
     dp[currnum]=min(q1,min(q2,q3));
 }
 return dp[n];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	fill(memo,memo+n+1,-1);//for loops
	int ans=reduce_no(n);
	cout<<ans;
}
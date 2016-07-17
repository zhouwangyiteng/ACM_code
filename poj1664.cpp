#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 15

int m,n,t;
int dp[MAXN][MAXN];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==0||j==1)
				{
					dp[i][j]=1;
					continue;
				}
				if(i<j)
					dp[i][j]=dp[i][i];
				else
					dp[i][j]=dp[i][j-1]+dp[i-j][j];
			}
		cout<<dp[m][n]<<endl;
	}

	return 0;  
}    

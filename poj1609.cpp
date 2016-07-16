#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 105

int dp[MAXN][MAXN];
int cnt[MAXN][MAXN];
int n,i,j,l,m;

int main()
{
	while(cin>>n)
	{
		if(n==0)
		{
			cout<<'*'<<endl;
			break;
		}
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<n;i++)
		{
			cin>>l>>m;
			cnt[l][m]++;
		}
		for(i=1;i<=100;i++)
			for(j=1;j<=100;j++)
				dp[i][j]=max(dp[i-1][j], dp[i][j-1])+cnt[i][j];
		cout<<dp[100][100]<<endl;
	}
	return 0;  
}    

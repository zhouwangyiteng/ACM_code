#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 110

int n,m,k,s;
int w[MAXN],d[MAXN],dp[MAXN][MAXN];

int MAX(int a,int b)
{
	return a>b?a:b;
}

int main()
{
    while(scanf("%d%d%d%d",&n,&m,&k,&s)==4)
    {
    	memset(dp,0,sizeof(dp));
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&w[i],&d[i]);
			for(int j=1;j<=s;j++)
				for(int v=d[i];v<=m;v++)
					dp[j][v]=MAX(dp[j][v],dp[j-1][v-d[i]]+w[i]);
		}
		if(dp[s][m]>=n)
		{
			for(int i=0;i<=m;i++)
				if(dp[s][i]>=n)
				{
					cout<<m-i<<endl;
					break;
				}
		}
		else
			cout<<-1<<endl;
	}
    
	return 0;  
}    

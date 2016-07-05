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
#define MAXN 65536

int w[1001],d[1001],dp[1001];
int MAX(int a,int b)
{
	return a>b?a:b;
}

int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>w[i];
		for(int i=1;i<=n;i++)
			cin>>d[i];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int v=m;v>=d[i];v--)	
				dp[v]=MAX(dp[v],dp[v-d[i]]+w[i]);
		cout<<dp[m]<<endl;
		
	}
    
	return 0;  
}    

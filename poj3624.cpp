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
#define MAXN 12888

int w[3405],d[3405],dp[MAXN];
int MAX(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			cin>>w[i]>>d[i];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int v=m;v>=w[i];v--)
				dp[v]=MAX(dp[v],dp[v-w[i]]+d[i]);
		cout<<dp[m]<<endl;
	}

	return 0;  
}    

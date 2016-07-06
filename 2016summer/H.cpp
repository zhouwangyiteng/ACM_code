#include<vector>
#include<cmath>
#include<algorithm>
#include <map>
#include <iostream>

using namespace std;
#define MAXM 100005
#define MAXN 505
#define INF 0x3f3f3f3f
int dp[MAXM];
int c[MAXN],w[MAXN];

int n,m;

int MAX(int a,int b)
{
	return a>b?a:b;
}

int main()
{	
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		for(int i=1;i<=n;i++)
			cin>>c[i]>>w[i];
		fill(dp,dp+MAXM,0);
		for(int i=1;i<=n;i++)
			for(int v=m;v>=c[i];v--)
				dp[v]=MAX(dp[v],dp[v-c[i]]+w[i]);
		cout<<dp[m]<<endl;
	}
	

	return 0;
}
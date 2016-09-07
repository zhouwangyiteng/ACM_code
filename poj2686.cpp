/*************************************************************************
	> File Name: poj2686.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月04日 星期日 19时41分51秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
using namespace std;
#define X first
#define Y second
#define LL long long
#define INF 0x3f3f3f3f
#define N 9
#define M 35
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int t[N];
int g[M][M];
double dp[1<<N][M];
int n,m,p,a,b;

void solve()
{
	for(int i=0;i<(1<<n);i++)
		fill(dp[i],dp[i]+m,INF);
	dp[0][a-1]=0;
	double res=INF;
	for(int S=0;S<(1<<n);S++)
	{
		for(int v=0;v<m;v++)
			for(int i=0;i<n;i++)
				if(!(S&(1<<i)))
					for(int u=0;u<m;u++)
						if(g[v][u]>=0)
							dp[S|(1<<i)][u]=min(dp[S|(1<<i)][u],dp[S][v]+(double)(g[v][u])/t[i]);
		res=min(res,dp[S][b-1]);
	}
	if(res==INF)
		printf("Impossible\n");
	else
		printf("%.3lf\n",res);
}

int main()
{
	while(scanf("%d %d %d %d %d",&n,&m,&p,&a,&b),n&&m)
	{
		for(int i=0;i<n;i++)
			scanf("%d",t+i);
		CLR(g,-1);
		for(int i=0;i<p;i++)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			g[x-1][y-1]=g[y-1][x-1]=z;
		}
		solve();
	}

	return 0;
}


/*************************************************************************
	> File Name: hdoj1706.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月11日 星期四 09时44分43秒
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
#define N 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int g[N][N],cnt[N][N];
int n,m,mx,ans;
int i,j,d,u,v;

void floyd()
{
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
		{
			if(g[i][k]==INF||i==k)
				continue;
			for(int j=1;j<=m;j++)
			{
				if(g[j][k]==INF||i==j||j==k)
					continue;
				if(g[i][j]>g[i][k]+g[k][j])
				{
					g[i][j]=g[i][k]+g[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j];
				}
				else if(g[i][j]==g[i][k]+g[k][j])
					cnt[i][j]+=cnt[i][k]*cnt[k][j];
			}
		}
}

int main()
{
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		CLR(g,0x3f);
		CLR(cnt,0);
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&u,&v,&d);
			if(u==v)
				continue;
			if(d<g[u][v])
			{
				g[u][v]=g[v][u]=d;
				cnt[u][v]=cnt[v][u]=1;
			}
			else if(g[u][v]==d)
			{
				cnt[u][v]++;
				cnt[v][u]++;
			}
		}
		floyd();
		ans=0;
		mx=-1;
		for(i=1;i<=m;i++)
			for(j=1;j<=i;j++)
			{
				if(g[i][j]==INF||i==j)
					continue;
				if(g[i][j]>mx)
				{
					mx=g[i][j];
					ans=cnt[i][j];
				}
				else if(g[i][j]==mx)
					ans+=cnt[i][j];
			}
		printf("%d %d\n",mx,ans);
	}

	return 0;
}


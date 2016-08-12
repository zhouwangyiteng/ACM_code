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
#include <fstream>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define CLR(a,x) memset(a,x,sizeof(a))
#define LL long long
#define INF 0X3f3f3f3f
#define N 35
#define M 1000000
using namespace std;

int g[N][N];
int vis[N],dist[N],p[N];
int n,m;
vector<int> que;

void dijk()
{
	int i,j,MIN;
	CLR(vis,0);
	vis[1]=1;
	dist[1]=0;
	for(int i=2;i<=n;i++)
	{
		dist[i]=g[1][i];
		p[i]=1;
	}
	p[1]=-1;
	int pre=1;
	for(int i=2;i<=n;i++)
	{
		MIN=INF;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dist[pre]+g[pre][j]<dist[j])
			{
				dist[j]=dist[pre]+g[pre][j];
				p[j]=pre;
			}
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dist[j]<MIN)
			{
				MIN=dist[j];
				pre=j;
			}
		vis[pre]=1;
	}
	
}	

bool dfs(int i,int len)
{
	if(i==n&&len==dist[n])
		return 1;
	for(int j=1;j<=n;j++)
		if(!vis[j]&&g[i][j]==1)
		{
			vis[j]=1;
			que.push_back(j);
			if(dfs(j,len+1))
				return 1;
			que.pop_back();
			vis[j]=0;
		}
	return 0;
}


int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		CLR(g,0x3f);
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			g[x][y]=g[y][x]=1;
		}
		dijk();
		if(dist[n]==INF)
			printf("No path.\n");
		else
		{
			CLR(vis,0);
			que.clear();
			printf("%d\n",dist[n]);
			que.push_back(1);
			vis[1]=1;
			dfs(1,0);
			cout<<que[0];
			for(int i=1;i<que.size();i++)
				printf(" %d",que[i]);
			printf("\n");
		}
	}
	
	return 0;
}













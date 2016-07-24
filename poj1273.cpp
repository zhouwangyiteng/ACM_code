/*************************************************************************
	> File Name: poj1273.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月24日 星期日 18时58分22秒
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
#define ll long long
#define INF 0x3f3f3f
#define MAXN 205
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int flow[MAXN][MAXN],cap[MAXN][MAXN];
int a[MAXN],p[MAXN];
int m,n;

int maxflow(int s,int t)
{
	queue<int> que;
	CLR(flow,0);
	int f=0;
	while(1)
	{
		CLR(a,0);
		a[s]=INF;
		que.push(s);
		while(!que.empty())
		{
			int u=que.front();
			que.pop();
			for(int v=1;v<=n;v++)
			{
				if(!a[v]&&cap[u][v]>flow[u][v])
				{
					p[v]=u;
					que.push(v);
					a[v]=min(a[u],cap[u][v]-flow[u][v]);
				}
			}
		}
		if(a[t]==0)
			break;
		for(int u=t;u!=s;u=p[u])
		{
			flow[p[u]][u]+=a[t];
			flow[u][p[u]]-=a[t];
		}
		f+=a[t];
	}
	return f;
}

int main()
{
	int u,v,w;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		CLR(cap,0);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			cap[u][v]+=w;
		}
		int ans=maxflow(1,n);
		cout<<ans<<endl;
	}

	return 0;
}


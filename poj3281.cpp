/*************************************************************************
	> File Name: poj3281.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月02日 星期二 10时04分36秒
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
#define INF 0x3f3f3f3f
#define N 410
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))


int cap[N][N];
int flow[N][N];
int a[N],p[N];
int n,f,d,s,t;

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
			for(int v=0;v<=t;v++)
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
	scanf("%d %d %d",&n,&f,&d);
	CLR(cap,0);
	s=2*n+f+d;
	t=s+1;
	for(int i=0;i<n;i++)
		cap[i][i+n]=1;
	for(int i=0;i<f;i++)
		cap[s][2*n+i]=1;
	for(int i=0;i<d;i++)
		cap[2*n+f+i][t]=1;
	for(int i=0;i<n;i++)
	{
		int ti,tj,x;
		scanf("%d %d",&ti,&tj);
		for(int j=0;j<ti;j++)
		{
			scanf("%d",&x);
			cap[2*n+x-1][i]=1;
		}
		for(int j=0;j<tj;j++)
		{
			scanf("%d",&x);
			cap[n+i][2*n+f+x-1]=1;
		}
	}
	int ans=maxflow(s,t);
	cout<<ans<<endl;

	return 0;
}


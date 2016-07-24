/*************************************************************************
	> File Name: poj3020.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月24日 星期日 14时30分15秒
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
#define MAXN 400
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dir[4][2]={0,1,0,-1,1,0,-1,0};
int p[41][11];
int g[MAXN][MAXN];
int vis[MAXN],match[MAXN];
int h,w,t,v,ans;
char ch[45];

int dfs(int u)
{
	int i;
	for(i=1;i<v;i++)
		if(!vis[i]&&g[u][i])
		{
			vis[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=u;
				return 1;
			}
		}
	return 0;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>h>>w;
		v=0;
		CLR(p,0);
		for(int i=0;i<h;i++)
		{
			scanf("%s",ch);
			for(int j=0;j<w;j++)
				if(ch[j]=='*')
					p[i][j]=++v;
				else
					p[i][j]=0;
		}
		CLR(g,0);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(p[i][j]!=0)
				{
					for(int k=0;k<4;k++)
					{
						int ti=i+dir[k][0];
						int tj=j+dir[k][1];
						if(p[ti][tj]!=0&&ti>=0&&ti<h&&tj>=0&&tj<w)
						{
							g[p[i][j]][p[ti][tj]]=1;
							g[p[ti][tj]][p[i][j]]=1;
						}
					}
				}
		CLR(match,0);
		ans=0;
		for(int i=1;i<=v;i++)
		{
			CLR(vis,0);
			if(dfs(i))
				ans++;
		}
		cout<<v-(1+ans)/2<<endl;
	}

	return 0;
}


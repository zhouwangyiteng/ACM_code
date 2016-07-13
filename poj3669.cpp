#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 400
#define INF 0x3f3f3f3f

int dir[4][2]={0,1,0,-1,1,0,-1,0};
struct node
{
	int x,y,tm;
	node(int x=0,int y=0,int tm=0):x(x),y(y),tm(tm){};
};
queue<node> que;
int m,ans;
int g[MAXN][MAXN];
int vis[MAXN][MAXN];
bool flag;

void bfs()
{
	que.push(node(0,0,0));
	vis[0][0]=1;
	while(!que.empty())
	{
		node p=que.front();
		que.pop();
		int tt=p.tm;
		for(int i=0;i<4;i++)
		{
			int ti=p.x+dir[i][0];
			int tj=p.y+dir[i][1];
			if(!vis[ti][tj]&&ti>=0&&ti<MAXN&&tj>=0&&tj<MAXN)
			{
				if(g[ti][tj]==-1)
				{
					flag=true;
					ans=tt+1;
					return;
				}
				if(g[ti][tj]>tt+1)
				{
					vis[ti][tj]=1;
					que.push(node(ti,tj,tt+1));
				}
			}	
		}
	}
}

int main()
{
	cin>>m;
	memset(g,-1,sizeof(g));
	memset(vis,false,sizeof(vis));
	flag=false;
	ans=0;
	while(m--)
	{
		int x,y,t;
		cin>>x>>y>>t;
		if(g[x][y]==-1)g[x][y]=t;
		else g[x][y]=g[x][y]<t?g[x][y]:t;
		for(int i=0;i<4;i++)
		{
			int tx=x+dir[i][0];
			int ty=y+dir[i][1];
			if(tx>=0&&tx<MAXN&&ty>=0&&ty<MAXN)
				if(g[tx][ty]==-1) g[tx][ty]=t;
				else g[tx][ty]=g[tx][ty]<t?g[tx][ty]:t;
		}	
	}
	while(!que.empty())
		que.pop();
	if(g[0][0]==-1)
		flag=true;
	else 
		if(g[0][0]==0);
		else bfs();
	if(flag)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
		
	return 0;  
}    

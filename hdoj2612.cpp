#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 205

int dir[4][2]={0,1,0,-1,1,0,-1,0};
struct node
{
	int x,y;
};

queue<node> que;
char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int cnt[MAXN][MAXN];
int tcnt[MAXN][MAXN];
int n,m,ans;
int yi,yj,mi,mj;

void bfs()
{
	while(!que.empty())
	{
		node p=que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			int ti=p.x+dir[i][0];
			int tj=p.y+dir[i][1];
			if(g[ti][tj]!='#'&&!vis[ti][tj]&&ti>=0&&ti<n&&tj>=0&&tj<m)
			{
				cnt[ti][tj]=cnt[p.x][p.y]+1;
				node tp;
				tp.x=ti;
				tp.y=tj;
				que.push(tp);
				vis[ti][tj]=1;
			}
		}
	}
}

int main()
{
    while(cin>>n>>m)
    {
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>g[i][j];
				if(g[i][j]=='Y')
				{
					yi=i;
					yj=j;
				}
				if(g[i][j]=='M')
				{
					mi=i;
					mj=j;
				}
			}
		memset(cnt,-1,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		while(!que.empty())
			que.pop();
		node s;
		s.x=yi;
		s.y=yj;
		que.push(s);
		vis[yi][yj]=1;
		cnt[yi][yj]=0;
		bfs();
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				tcnt[i][j]=cnt[i][j];
				
		memset(cnt,-1,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		while(!que.empty())
			que.pop();
		s.x=mi;
		s.y=mj;
		que.push(s);
		vis[mi][mj]=1;
		cnt[mi][mj]=0;
		bfs();
		
		ans=MAXN*MAXN;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(g[i][j]=='@'&&cnt[i][j]>=0&&tcnt[i][j]>=0&&((cnt[i][j]+tcnt[i][j])<ans))
					ans=cnt[i][j]+tcnt[i][j];
		cout<<11*ans<<endl;
	}
    
	return 0;  
}    

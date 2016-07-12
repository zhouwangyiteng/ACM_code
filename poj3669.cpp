#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 105

int dir[4][2]={0,1,0,-1,1,0,-1,0};
struct node
{
	int x,y;
};
queue<node> que;
int w,h,si,sj,cnt;
char g[MAXN][MAXN];
int vis[MAXN][MAXN];
char flag;

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
			if(g[ti][tj]==flag&&!vis[ti][tj]&&ti>=0&&ti<h&&tj>=0&&tj<w)
			{
				node tmp;
				tmp.x=ti;
				tmp.y=tj;
				vis[ti][tj]=1;
				que.push(tmp);
			}
		}
	}
}

int main()
{
	while(cin>>h>>w)
	{
		if(w==0&&h==0) break;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin>>g[i][j];
		while(!que.empty())
			que.pop();
		memset(vis,0,sizeof(vis));
		cnt=0;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(!vis[i][j])
				{
					flag=g[i][j];
					cnt++;
					node p;
					p.x=i;
					p.y=j;
					que.push(p);
					vis[i][j]=1;
					bfs();
				}
		cout<<cnt<<endl;
	}

	return 0;  
}    

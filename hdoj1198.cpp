/*************************************************************************
	> File Name: hdoj1198.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月02日 星期五 19时26分05秒
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
#define N 110
#define M 55
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int x,y;
	node(){};
	node(int a,int b):x(a),y(b){};
};
queue<node> que;
int g[N][N],vis[N][N];
int n,m,cnt;
int dir[4][2]={0,1,0,-1,1,0,-1,0};

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
			int tx=p.x+dir[i][0]*2;
			int ty=p.y+dir[i][1]*2;
			if(ti>0&&tj>0&&ti<2*n&&tj<2*m&&g[ti][tj]==2&&!vis[tx][ty])
			{
				vis[tx][ty]=cnt;
				que.push(node(tx,ty));
			}
		}
	}
}

void up(int x,int y)
{
	g[x-1][y]++;
}
void down(int x,int y)
{
	g[x+1][y]++;
}
void left(int x,int y)
{
	g[x][y-1]++;
}
void right(int x,int y)
{
	g[x][y+1]++;
}

void plot(int x,int y,char ch)
{
	if(ch=='A')
	{
		up(x,y);
		left(x,y);
	}
	else if(ch=='B')
	{
		up(x,y);
		right(x,y);
	}
	else if(ch=='C')
	{
		left(x,y);
		down(x,y);
	}
	else if(ch=='D')
	{
		right(x,y);
		down(x,y);
	}
	else if(ch=='E')
	{
		up(x,y);
		down(x,y);
	}
	else if(ch=='F')
	{
		left(x,y);
		right(x,y);
	}
	else if(ch=='G')
	{
		up(x,y);
		left(x,y);
		right(x,y);
	}
	else if(ch=='H')
	{
		up(x,y);
		down(x,y);
		left(x,y);
	}
	else if(ch=='I')
	{
		left(x,y);
		right(x,y);
		down(x,y);
	}
	else if(ch=='J')
	{
		up(x,y);
		down(x,y);
		right(x,y);
	}
	else
	{
		up(x,y);
		down(x,y);
		left(x,y);
		right(x,y);
	}
}

int main()
{
	while(cin>>n>>m,n>0&&m>0)
	{
		CLR(g,0);
		CLR(vis,0);
		for(int i=1;i<=n;i++)
		{
			getchar();
			for(int j=1;j<=m;j++)
			{
				int x=2*i-1;
				int y=2*j-1;
				char ch;
				scanf("%c",&ch);
				plot(x,y,ch);
			}
		}
		while(!que.empty())
			que.pop();
		cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!vis[2*i-1][2*j-1])
				{
					cnt++;
					vis[2*i-1][2*j-1]=cnt;
					que.push(node(2*i-1,2*j-1));
					bfs();
				}
		printf("%d\n",cnt);
	}

	return 0;
}


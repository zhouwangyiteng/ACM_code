#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 22

int dir[4][2]={0,1,0,-1,1,0,-1,0};
struct node
{
	int x,y;
};
queue<node> que;
int w,h,si,sj,cnt;
char g[MAXN][MAXN];

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
			if(g[ti][tj]=='.'&&ti>=0&&ti<h&&tj>=0&&tj<w)
			{
				node tmp;
				tmp.x=ti;
				tmp.y=tj;
				cnt++;
				g[ti][tj]='#';
				que.push(tmp);
			}
		}
	}
}

int main()
{
	while(cin>>w>>h)
	{
		if(w==0&&h==0) break;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				cin>>g[i][j];
				if(g[i][j]=='@')
				{
					si=i;
					sj=j;
				}
			}
		while(!que.empty())
			que.pop();
		cnt=1;
		node p;
		p.x=si;
		p.y=sj;
		que.push(p);
		g[si][sj]='#';
		bfs();
		cout<<cnt<<endl;
	}

	return 0;  
}    

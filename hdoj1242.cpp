#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 201

struct node
{
	int i,j,step;
	friend bool operator < (node a,node b)
	{
		return a.step>b.step;
	}
};
priority_queue<node> que;
char g[MAXN][MAXN];
int dir[4][2]={0,-1,0,1,1,0,-1,0};
int n,m,ai,aj,step;
bool yes;

void bfs()
{
	while(!que.empty())
	{
		node p=que.top(),tmp;
		que.pop();	
		for(int i=0;i<4;i++)
		{
			int ti=p.i+dir[i][0];
			int tj=p.j+dir[i][1];
			if(ti>=0&&ti<n&&tj>=0&&tj<m&&g[ti][tj]!='#')
			{
				tmp.i=ti;
				tmp.j=tj;
				if(tmp.i==ai&&tmp.j==aj)
				{
					step=p.step+1;
					yes=true;
					return;
				}
				if(g[ti][tj]=='x')
					tmp.step=p.step+2;	
				else 
					tmp.step=p.step+1;
				que.push(tmp);
				g[ti][tj]='#';
			}
		}
		
	}
}


int main()
{
    while(cin>>n>>m)
    {
    	int ri,rj;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>g[i][j];
				if(g[i][j]=='r') {ri=i;rj=j;}
				else if(g[i][j]=='a') {ai=i;aj=j;}
			}
		yes=false;
		while(!que.empty())
			que.pop();
		node p;
		p.i=ri;p.j=rj;p.step=0;
		g[ri][rj]='#';
		que.push(p);
		bfs();
		if(yes)
			cout<<step<<endl;
		else
			cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
	}
    
	return 0;  
}    

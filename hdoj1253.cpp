#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 55

struct node
{
	int i,j,k,step;
};
queue<node> que;
int g[MAXN][MAXN][MAXN];
int dir[6][3]={0,0,1,0,0,-1,1,0,0,-1,0,0,0,1,0,0,-1,0};
int a,b,c,t,k;

int bfs()
{
	while(!que.empty())
	{
		node p=que.front();
		que.pop();
		for(int i=0;i<6;i++)
		{
			int ti=p.i+dir[i][0];
			int tj=p.j+dir[i][1];
			int tk=p.k+dir[i][2];
			if(!g[ti][tj][tk]&&ti>=0&&ti<a&&tj>=0&&tj<b&&tk>=0&&tk<c)
			{
				if(ti==a-1&&tj==b-1&&tk==c-1)
					return p.step+1;
				node tmp;
				tmp.i=ti;
				tmp.j=tj;
				tmp.k=tk;
				tmp.step=p.step+1;
				g[ti][tj][tk]=1;
				que.push(tmp);
			}
		}
	}
	return t+1;
}

int main()
{
    cin>>k;
    while(k--)
    {
		scanf("%d%d%d%d",&a,&b,&c,&t);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				for(int k=0;k<c;k++)
					scanf("%d",&g[i][j][k]);
		while(!que.empty())
			que.pop();
		node p;
		g[0][0][0]=1;
		p.i=0;p.j=0;p.k=0;p.step=0;
		que.push(p);
		int cnt=bfs();
		if(cnt<=t)
			cout<<cnt<<endl;
		else
			cout<<-1<<endl;
	}
    
	return 0;  
}    

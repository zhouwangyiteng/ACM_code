#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<queue>
#include<algorithm>
using namespace std;
#define MAXN 25

struct node
{
	int i,j;
};
queue<node> que;
char g[MAXN][MAXN];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int n,m,cnt,si,sj;

void bfs()
{
	while(!que.empty())
	{
		node p=que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{	
			node tmp;
			tmp.i=p.i+dir[i][0];
			tmp.j=p.j+dir[i][1];
			if(g[tmp.i][tmp.j]!='#'&&tmp.i>=0&&tmp.i<n&&tmp.j>=0&&tmp.j<m)
			{
				cnt++;
				que.push(tmp);
				g[tmp.i][tmp.j]='#';
			}
		}
	}
}

int main()
{
	while(cin>>m>>n)
	{
		if(n==0&&m==0) break;
		node p;	
		cnt=1;
		while(!que.empty())
			que.pop();
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>g[i][j];
				if(g[i][j]=='@')
				{
					p.i=i;
					p.j=j;
					g[i][j]='#';
				}
			}
		que.push(p);
		bfs();
		cout<<cnt<<endl;
	}    
    
	return 0;  
}    

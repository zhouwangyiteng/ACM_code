#include<vector>
#include<cmath>
#include<algorithm>
#include <map>
#include<queue>
#include <iostream>

using namespace std;
#define MAXN 15
#define INF 0x3f3f3f3f

struct node
{
	int x,y;
};
queue<node> que;
char g[MAXN][MAXN];
int n,m,cnt;
int flag=1;
int dir[4][2]={0,1,0,-1,1,0,-1,0};

bool yes(int i,int j)
{
	int ti=i,tj=j;
	while(g[i][tj]=='.'&&tj<m)tj++;
	if(tj==m) return false;
	tj=j;
	while(g[i][tj]=='.'&&tj>=0)tj--;
	if(tj==-1) return false;
	while(g[ti][j]=='.'&&ti<n)ti++;
	if(ti==n) return false;
	ti=i;
	while(g[ti][j]=='.'&&ti>=0)ti--;
	if(ti==-1) return false;
	return true;
}

void bfs()
{
	while(!que.empty())
	{
		node q=que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			int ti=q.x+dir[i][0];
			int tj=q.y+dir[i][1];
			if(g[ti][tj]=='.'&&ti>=0&&ti<n&&tj>=0&&tj<m)
			{
				node tmp;
				tmp.x=ti;
				tmp.y=tj;
				g[ti][tj]='/';
				que.push(tmp);
				cnt+=2;
			}
		}
	}
}

int main()
{
	while(cin>>n>>m)
	{
		cnt=0;
		int si=-1,sj=-1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>g[i][j];
				if(g[i][j]!='.')
					cnt++;
			}
		for(int i=n-1;i>=0&&si==-1;i--)
			for(int j=m-1;j>=0&&si==-1;j--)
				if(g[i][j]=='.'&&yes(i,j))
				{
					si=i;
					sj=j;
				}
		while(!que.empty())
			que.pop();
		node pq;
		pq.x=si;
		pq.y=sj;
		g[si][sj]='/';
		cnt+=2;
		que.push(pq);
		bfs();
		cout<<cnt<<endl;
	}	

	return 0;
}

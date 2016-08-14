/*************************************************************************
	> File Name: hdoj1428.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月14日 星期日 20时35分49秒
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
#define N 55
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int x,y;
	int step;
	node(){};
	node(int a,int b,int z):x(a),y(b),step(z){};
	bool operator < (const node &a) const  
    {  
        return a.step<step;
    } 
};

int dir[4][2]={0,1,0,-1,1,0,-1,0};
priority_queue<node> que;
int g[N][N],dist[N][N];
LL dp[N][N];
int n;

void bfs()
{
	node q;
	que.push(node(n,n,g[n][n]));
	dist[n][n]=g[n][n];
	g[n][n]=-1;
	while(!que.empty())
	{
		q=que.top();
		que.pop();
		for(int i=0;i<4;i++)
		{
			int ti=q.x+dir[i][0];
			int tj=q.y+dir[i][1];
			if(ti>0&&ti<=n&&tj>0&&tj<=n&&g[ti][tj]!=-1)
			{
				dist[ti][tj]=q.step+g[ti][tj];
				que.push(node(ti,tj,dist[ti][tj]));
				g[ti][tj]=-1;
			}
		}
	}

}

LL dfs(int x,int y)
{
	if(dp[x][y])
		return dp[x][y];
	 for(int i=0;i<4;i++)
	 {
	 	int ti=x+dir[i][0];
	 	int tj=y+dir[i][1];
	 	if(ti>0&&ti<=n&&tj>0&&tj<=n&&dist[x][y]>dist[ti][tj])
	 		dp[x][y]+=dfs(ti,tj);
	 }
	 return dp[x][y];
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&g[i][j]);
		CLR(dist,0);
		while(!que.empty())
			que.pop();
		bfs();
		CLR(dp,0);
		dp[n][n]=1;
		printf("%lld\n",dfs(1,1));
	}

	return 0;
}


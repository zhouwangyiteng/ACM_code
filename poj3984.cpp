/*************************************************************************
	> File Name: poj3984.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月18日 星期四 11时02分04秒
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
#define N 5
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int x,y,step;
	node(){};
	node(int a,int b,int s):x(a),y(b),step(s){};
};

int m[N][N];
struct pnode
{
	int px,py;
}p[N][N];
int n;
queue<node> que;
int dir[4][2]={0,1,0,-1,1,0,-1,0};

void bfs()
{
	node q;
	while(!que.empty())
	{
		q=que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			int tx=q.x+dir[i][0];
			int ty=q.y+dir[i][1];
			if(tx>=0&&tx<n&&ty>=0&&ty<n&&!m[tx][ty])
			{
				m[tx][ty]=1;
				p[tx][ty].px=q.x;
				p[tx][ty].py=q.y;
				que.push(node(tx,ty,q.step+1));
			}
		}
	}
}

void show(int x,int y)
{
	if(x==-1&&y==-1)
		return;
	show(p[x][y].px,p[x][y].py);
	printf("(%d, %d)\n",x,y);
}

int main()
{
	n=5;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&m[i][j]);
	p[0][0].px=-1;
	p[0][0].py=-1;
	while(!que.empty())
		que.pop();
	que.push(node(0,0,0));
	m[0][0]=1;
	bfs();
	show(n-1,n-1);

	return 0;
}


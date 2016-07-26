/*************************************************************************
	> File Name: 1004.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月26日 星期二 14时15分16秒
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
#define ll long long
#define INF 0x3f3f3f3f
#define N 35
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dir[4][2]={0,1,0,-1,1,0,-1,0};
int t,m,n;
int tile[N][N];
int flip[N][N];

int get(int x,int y)
{
	int c=tile[x][y];
	if(flip[x][y])
		c+=2;
	for(int i=0;i<4;i++)
	{
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if(tx>=0&&tx<m&&ty>=0&&ty<n)
			c+=flip[tx][ty];
	}
	return c%3;
}

int calc()
{
	for(int i=1;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(get(i-1,j))
				flip[i][j]=1;
			if(get(i-1,j))
				return -1;
		}
	for(int j=0;j<n;j++)
		if(get(m-1,j))
			return -1;
	int res=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			res+=flip[i][j];
	return res;
}

void solve()
{
	int res;
	for(int i=0;i< 1<<n;i++)
	{
		CLR(flip,0);
		for(int j=0;j<n;j++)
			flip[0][n-j-1]=i>>j&1;
		res=calc();
		if(res>=0)
			break;
	}
	if(res>=0)
	{
		printf("%d\n",res);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
				if(flip[i][j]==1)
					printf("%d %d\n",i+1,j+1);
		}
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&tile[i][j]);
		solve();
	}

	return 0;
}


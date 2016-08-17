/*************************************************************************
	> File Name: poj1088.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月17日 星期三 10时34分47秒
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
#define N  105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N][N],g[N][N];
int r,c,ans;
int dir[4][2]={0,1,0,-1,-1,0,1,0};

int DP(int x,int y)
{
	if(dp[x][y])
		return dp[x][y];
	for(int i=0;i<4;i++)
	{
		int ti=x+dir[i][0];
		int tj=y+dir[i][1];
		if(ti>=0&&ti<r&&tj>=0&&tj<c)
		{
			if(g[ti][tj]<g[x][y])
				dp[x][y]=max(dp[x][y],DP(ti,tj));
		}
	}
	return ++dp[x][y];
}

int main()
{
	cin>>r>>c;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&g[i][j]);
	CLR(dp,0);
	ans=0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			DP(i,j);
			ans=max(dp[i][j],ans);
		}
	cout<<ans<<endl;

	return 0;
}


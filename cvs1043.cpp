/*************************************************************************
	> File Name: cvs1043.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月05日 星期一 15时14分59秒
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
#define N 12
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[2*N][N][N];
int g[N][N];
int n;

int main()
{
	scanf("%d",&n);
	CLR(g,0);
	int x,y,z;
	while(scanf("%d %d %d",&x,&y,&z),x||y||z)
		g[x][y]=z;
	CLR(dp,0);
	for(int i=1;i<2*n;i++)
		for(x=1;x<=n;x++)
			for(y=1;y<=n;y++)
			{
				if(x>i)continue;
				if(y>i)continue;
				if(i-x+1>n)continue;
				if(i-y+1>n)continue;
				int tmp=max(dp[i-1][x-1][y],dp[i-1][x][y-1]);
				tmp=max(tmp,dp[i-1][x][y]);
				tmp=max(tmp,dp[i-1][x-1][y-1]);
				dp[i][x][y]+=tmp;
				if(x==y)
					dp[i][x][y]+=g[x][i-x+1];
				else
					dp[i][x][y]+=g[x][i-x+1]+g[y][i-y+1];
			}
	printf("%d\n",dp[2*n-1][n][n]);

	return 0;
}


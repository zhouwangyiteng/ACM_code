/*************************************************************************
	> File Name: cvs1169.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月05日 星期一 15时36分38秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))
int dp[2*N][N][N];
int g[N][N];
int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&g[i][j]);
	CLR(dp,0);
	for(int i=2;i<n+m-1;i++)
		for(int x=1;x<=n;x++)
			for(int y=1;y<=n;y++)
			{
				if(x>i)continue;
				if(y>i)continue;
				if(i-x+1>m)continue;
				if(i-y+1>m)continue;
				if(x==y)continue;
				int tmp=max(dp[i-1][x-1][y],dp[i-1][x][y-1]);
				tmp=max(tmp,dp[i-1][x][y]);
				tmp=max(tmp,dp[i-1][x-1][y-1]);
				dp[i][x][y]+=tmp+g[x][i-x+1]+g[y][i-y+1];
			}
	printf("%d\n",max(dp[n+m-2][n-1][n],dp[n+m-2][n][n-1]));

	return 0;
}

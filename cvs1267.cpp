/*************************************************************************
	> File Name: cvs1267.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月05日 星期一 16时31分01秒
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
#define N 30
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N][N];
int n,m,x,y,k;

int main()
{
	scanf("%d %d",&n,&m);
	CLR(dp,0);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d",&x,&y);
		dp[x][y]=-1;
	}
	dp[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(dp[i][j]>=0)
			{
				x=max(0,dp[i-1][j]);
				y=max(0,dp[i][j-1]);
				dp[i][j]+=x+y;
			}
	printf("%d\n",dp[n][m]);

	return 0;
}


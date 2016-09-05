/*************************************************************************
	> File Name: cvs1219.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月05日 星期一 16时03分12秒
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

LL dp[N][N];
int dir[4][2]={-1,2,-1,-2,-2,1,-2,-1};
int n,m,x1,x2,Y1,y2;

int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d %d %d",&x1,&Y1,&x2,&y2);
	CLR(dp,0);
	if(x1>x2)
	{
		x1^=x2;
		x2^=x1;
		x1^=x2;
		Y1^=y2;
		y2^=Y1;
		Y1^=y2;
	}
	dp[x1][Y1]=1;
	for(int x=x1+1;x<=x2;x++)
		for(int y=1;y<=m;y++)
			for(int i=0;i<4;i++)
			{
				int tx=x+dir[i][0];
				int ty=y+dir[i][1];
				if(tx>0&&tx<=n&&ty>0&&ty<=m)
					dp[x][y]+=dp[tx][ty];
			}
	printf("%lld\n",dp[x2][y2]);

	return 0;
}


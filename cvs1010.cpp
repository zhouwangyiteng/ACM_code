/*************************************************************************
	> File Name: cvs1010.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月09日 星期日 22时02分21秒
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
#define N 25
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

LL dp[N][N];
int vis[N][N];
int n,m,a,b;
int dir[9][2]={0,0,1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};

int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	n++,m++,a++,b++;
	CLR(dp,0);
	CLR(vis,0);
	for(int i=0;i<9;i++)
	{
		int ta=a+dir[i][0];
		int tb=b+dir[i][1];
		if(ta>0&&ta<=n&&tb>0&&tb<=m)
			vis[ta][tb]=1;
	}
	dp[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if((i==1&&j==1)||vis[i][j])
				continue;
			dp[i][j]=dp[i][j-1]+dp[i-1][j];
		}
	cout<<dp[n][m]<<endl;

	return 0;
}


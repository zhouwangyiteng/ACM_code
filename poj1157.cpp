/*************************************************************************
	> File Name: poj1157.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月20日 星期六 15时38分23秒
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
#define N 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,m;
int a[N][N],dp[N][N];

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		CLR(dp,-INF);
		for(int i=0;i<=m;i++)
			dp[0][i]=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=m;j++)
				dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+a[i][j]);
		cout<<dp[n][m]<<endl;
	}

	return 0;
}


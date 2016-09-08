/*************************************************************************
	> File Name: hdoj1559.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月08日 星期四 18时38分30秒
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
#define N 1005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

LL dp[N][N];
int n,m,x,y;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&n,&m,&x,&y);
		CLR(dp,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%lld",&dp[i][j]);
				dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			}
		LL ans=0;
		for(int i=n-x+1;i>=1;i--)
			for(int j=m-y+1;j>=1;j--)
				ans=max(ans,dp[i+x-1][j+y-1]-dp[i-1][j+y-1]-dp[i+x-1][j-1]+dp[i-1][j-1]);
		cout<<ans<<endl;
	}

	return 0;
}


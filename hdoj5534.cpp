/*************************************************************************
	> File Name: hdoj5534.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月03日 星期六 09时55分37秒
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
#define N 2020
#define M 10005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int t,n;
int f[N];
int dp[2][N];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<n;i++)
			scanf("%d",f+i);
		int cur=1;
		CLR(dp,0);
		dp[1][0]=n*f[1];
		for(int i=2;i<n;i++)
		{
			cur^=1;
			CLR(dp[cur],0);
			for(int j=0;j<i-1;j++)
				dp[cur][j]=dp[cur^1][j];
			for(int j=i-1;j<=n-2;j++)
				dp[cur][j]=max(dp[cur^1][j],dp[cur][j-i+1]+f[i]-f[1]);
		}
		cout<<dp[cur][n-2]<<endl;
	}

	return 0;
}


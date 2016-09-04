/*************************************************************************
	> File Name: cvs1048.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月04日 星期日 21时39分21秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N][N];
int w[N],sum[N];
int n;

int main()
{
	scanf("%d",&n);
	CLR(dp,0x3f);
	CLR(sum,0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",w+i);
		sum[i]=w[i]+sum[i-1];
		dp[i][i]=0;
	}
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
	printf("%d\n",dp[1][n]);

	return 0;
}


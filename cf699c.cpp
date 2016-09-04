/*************************************************************************
	> File Name: cf699c.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月04日 星期日 12时42分52秒
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

int dp[N][3];
int a;
int n;

int main()
{
	scanf("%d",&n);
	CLR(dp[0],0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a==0)
		{
			dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
			dp[i][1]=INF;
			dp[i][2]=INF;
		}
		else if(a==1)
		{
			dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
			dp[i][2]=INF;
		}
		else if(a==2)
		{
			dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
			dp[i][1]=INF;
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		}
		else
		{
			dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		}
	}
	printf("%d\n",min(min(dp[n][0],dp[n][1]),dp[n][2]));

	return 0;
}


/*************************************************************************
	> File Name: cf545c.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月30日 星期五 19时59分06秒
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
#define N 100005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n;
int x[N],h[N];
int dp[N][3];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",x+i,h+i);
	CLR(dp,0);
	dp[1][1]=1;
	if(x[1]+h[1]<x[2])
		dp[1][2]=1;
	for(int i=2;i<n;i++)
	{
		dp[i][1]=dp[i][2]=dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		if(x[i]-h[i]>x[i-1])
			dp[i][1]=max(dp[i-1][1]+1,dp[i-1][0]+1);
		if(x[i]-h[i]>x[i-1]+h[i-1])
			dp[i][1]=max(dp[i][1],dp[i-1][2]+1);
		if(x[i]+h[i]<x[i+1])
			dp[i][2]=dp[i][0]+1;
	}
	dp[n][1]=dp[n][2]=dp[n][0]=max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
	dp[n][2]=dp[n][0]+1;
	if(x[n]-h[n]>x[n-1])
		dp[n][1]=max(dp[n-1][1]+1,dp[n-1][0]+1);
	if(x[n]-h[n]>x[n-1]+h[n-1])
		dp[n][1]=max(dp[n][1],dp[n-1][2]+1);
	cout<<max(dp[n][1],dp[n][2])<<endl;

	return 0;
}


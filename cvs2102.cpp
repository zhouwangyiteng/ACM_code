/*************************************************************************
	> File Name: cvs2102.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月05日 星期一 21时46分24秒
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
#define N 205
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N],sum[N];
int dp[N][N],dp2[N][N];
int n;

int main()
{
	scanf("%d",&n);
	CLR(dp,0x3f);
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
		a[i+n]=a[i];
		dp[i][i]=0;
	}
	n*=2;
	for(int i=n/2+1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		dp[i][i]=0;
	}
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
	int ans=INF;
	for(int i=1;i<=n/2;i++)
		ans=min(ans,dp[i][i+n/2-1]);
	printf("%d\n",ans);	
	CLR(dp,0x3f);
	for(int i=1;i<=n;i++)
	{
		a[i]*=-1;
		sum[i]*=-1;
		dp[i][i]=0;	
	}
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
	ans=INF;
	for(int i=1;i<=n/2;i++)
		ans=min(ans,dp[i][i+n/2-1]);
	printf("%d\n",-ans);	

	return 0;
}


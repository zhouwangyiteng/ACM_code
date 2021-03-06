/*************************************************************************
	> File Name: poj1163.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月19日 星期五 16时10分13秒
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

int n;
int a[N][N];
int dp[N][N];

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				scanf("%d",&a[i][j]);
		CLR(dp,0);
		for(int i=1;i<=n;i++)
			dp[n][i]=a[n][i];
		for(int i=n-1;i>=1;i--)
			for(int j=1;j<=i;j++)
				dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
		cout<<dp[1][1]<<endl;
	}

	return 0;
}


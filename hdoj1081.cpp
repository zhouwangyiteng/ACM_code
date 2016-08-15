/*************************************************************************
	> File Name: hdoj1081.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月15日 星期一 11时22分32秒
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
int dp[N][N],num[N][N];

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		CLR(dp,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&num[i][j]);
				dp[i][j]=dp[i][j-1]+num[i][j];
			}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
			{
				int tmp=-1;
				for(int k=1;k<=n;k++)
				{
					tmp=max(tmp,0)+dp[k][i]-dp[k][j-1];
					ans=max(ans,tmp);
				}
			}
		cout<<ans<<endl;
	}

	return 0;
}


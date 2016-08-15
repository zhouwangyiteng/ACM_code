/*************************************************************************
	> File Name: hdoj1158.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月15日 星期一 19时22分00秒
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
#define N 13
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n;
int mp[N];
int dp[N][1000];
int hc,fc,sa,maxp;

int main()
{
	while(scanf("%d",&n),n)
	{
		scanf("%d %d %d",&hc,&sa,&fc);
		maxp=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",mp+i);
			maxp=max(maxp,mp[i]);
		}
		for(int i=mp[1];i<=maxp;i++)
			dp[1][i]=i*(hc+sa);
		for(int i=2;i<=n;i++)
			for(int j=mp[i];j<=maxp;j++)
			{
				int MIN=INF;
				for(int k=mp[i-1];k<=maxp;k++)
					if(k>=j)
						MIN=min(MIN,dp[i-1][k]+j*sa+(k-j)*fc);
					else
						MIN=min(MIN,dp[i-1][k]+j*sa+(j-k)*hc);
				dp[i][j]=MIN;
			}
		int ans=INF;
		for(int i=mp[n];i<=maxp;i++)
			ans=min(ans,dp[n][i]);
		cout<<ans<<endl;
	}

	return 0;
}


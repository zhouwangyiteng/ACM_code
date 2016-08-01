/*************************************************************************
	> File Name: hdoj1087.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月01日 星期一 09时53分16秒
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
#define ll long long
#define INF 0x3f3f3f3f
#define N 1005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N],a[N];
int n;

int main()
{
	while(cin>>n,n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		CLR(dp,0);
		dp[1]=a[1];
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			dp[i]=a[i];
			for(int j=1;j<=i-1;j++)
				if(a[i]>a[j]&&dp[j]+a[i]>dp[i])
					dp[i]=dp[j]+a[i];
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}

	return 0;
}


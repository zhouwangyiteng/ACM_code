/*************************************************************************
	> File Name: hdoj1423.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月07日 星期日 14时19分56秒
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
#define N 505
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int t,n1,n2,l1[N],l2[N],dp[N];

int LCIS()
{
	for(int i=1;i<=n1;i++)
	{
		int k=1;
		for(int j=1;j<=n2;j++)
			if(l1[i]==l2[j])
				dp[j]=max(dp[j],dp[k]+1);
			else 
				if(l1[i]>l2[j]&&dp[k]<dp[j])
					k=j;
	}
	int mx=0;
	for(int i=1;i<=n2;i++)
		mx=max(mx,dp[i]);
	return mx;
}

int main()
{
	cin>>t;
	while(t--)
	{
		CLR(dp,0);
		scanf("%d",&n1);
		for(int i=1;i<=n1;i++)
			scanf("%d",l1+i);
		scanf("%d",&n2);
		for(int i=1;i<=n2;i++)
			scanf("%d",l2+i);
		printf("%d\n",LCIS());
		if(t)
			printf("\n");
	}

	return 0;
}


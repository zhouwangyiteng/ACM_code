/*************************************************************************
	> File Name: hdoj5748.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月24日 星期日 19时50分02秒
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
#define INF 0x3f3f3f3F
#define MAXN 100005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[MAXN],dp[MAXN],m[MAXN];
int t,n;

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			m[i]=INF;
		}
		for(int i=1;i<=n;i++)
		{
			int p=lower_bound(m+1,m+n+1,a[i])-m;
			dp[i]=p;
			m[p]=a[i];
		}
		for(int i=1;i<n;i++)
			printf("%d ",dp[i]);
		printf("%d\n",dp[n]);
	}

	return 0;
}


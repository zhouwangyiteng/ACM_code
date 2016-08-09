/*************************************************************************
	> File Name: poj2342.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月09日 星期二 20时30分09秒
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
#define N 6005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,root;
int p[N];
int dp[N][2];
bool vis[N];

void treeDP(int root)
{
	vis[root]=1;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&p[i]==root)
		{
			treeDP(i);
			dp[root][1]+=dp[i][0];
			dp[root][0]+=max(dp[i][0],dp[i][1]);
		}
}

int main()
{
	while(cin>>n,n)
	{
		CLR(p,0);
		CLR(vis,0);
		CLR(dp,0);
		for(int i=1;i<=n;i++)
			scanf("%d",&dp[i][1]);
		for(int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			p[a]=b;
			root=b;
		}
		while(p[root])
			root=p[root];
		treeDP(root);
		printf("%d\n",max(dp[root][0],dp[root][1]));
	}

	return 0;
}


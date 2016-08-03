/*************************************************************************
	> File Name: hdoj1955.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月03日 星期三 11时06分40秒
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
#define N 405
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

vector<int> a[N];
bool dp[N][N],vis[N];
int p[N],q[N];
int n,m,w,b,tot;

void dfs(int x)
{
	int i,y;
	vis[x]=1;
	if(x<=n)
		w++;
	else
		b++;
	for(i=0;i<a[x].size();i++)
	{
		y=a[x][i];
		if(!vis[y])
			dfs(y);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<=n+n;i++)
			a[i].clear();
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			a[x].push_back(y+n);
			a[y+n].push_back(x);
		}
		CLR(vis,0);
		CLR(dp,0);
		tot=0;
		for(int i=1;i<=n+n;i++)
			if(!vis[i])
			{
				b=w=0;
				dfs(i);
				p[++tot]=w;
				q[tot]=b;
			}
		dp[0][0]=true;
		for(int i=1;i<=tot;i++)
			for(int j=n/2;j>=p[i];j--)
				for(int k=n/2;k>=q[i];k--)
					if(dp[j-p[i]][k-q[i]])
						dp[j][k]=true;
		int i;
		for(i=n/2;i>=0;i--)
			if(dp[i][i])
				break;
		cout<<i<<endl;
	}

	return 0;
}


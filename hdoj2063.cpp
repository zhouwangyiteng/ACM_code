/*************************************************************************
	> File Name: hdoj2063.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月24日 星期日 11时48分22秒
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
#define INF 0x3f3f3f
#define MAXN 505
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int g[MAXN][MAXN];
int vis[MAXN];
int match[MAXN];
int v1,v2;
int k,ans;

int dfs(int u)
{
	int i;
	for(i=1;i<=v2;i++)
		if(!vis[i]&&g[u][i])
		{
			vis[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=u;
				return 1;
			}
		}
	return 0;
}

int main()
{
	while(cin>>k,k)
	{
		cin>>v1>>v2;
		CLR(g,0);
		CLR(match,0);
		ans=0;
		for(int i=0;i<k;i++)
		{
			int a,b;
			cin>>a>>b;
			g[a][b]=1;
		}
		for(int i=1;i<=v1;i++)
		{
			CLR(vis,0);
			if(dfs(i))
				ans++;
		}
		cout<<ans<<endl;
	}

	return 0;
}


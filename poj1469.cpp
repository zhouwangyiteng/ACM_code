/*************************************************************************
	> File Name: poj1469.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月24日 星期日 15时04分53秒
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
#define MAXN 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int g[105][305];
int vis[305];
int match[305];
int p,n,t,ans;

int dfs(int u)
{
	int i;
	for(i=1;i<=n;i++)
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
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&p,&n);
		CLR(g,0);
		CLR(match,0);
		for(int i=1;i<=p;i++)
		{
			int cnt,stu;
			scanf("%d",&cnt);
			for(int j=0;j<cnt;j++)
			{
				scanf("%d",&stu);
				g[i][stu]=1;
			}
		}
		ans=0;
		for(int i=1;i<=p;i++)
		{
			CLR(vis,0);
			if(dfs(i))
				ans++;
		}
		if(ans==p)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}


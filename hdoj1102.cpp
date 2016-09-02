/*************************************************************************
	> File Name: hdoj1102.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月02日 星期五 16时42分00秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int g[N][N],vis[N],dist[N];
int n,m,ans,x,y;

void prim(int a)
{
	vis[a]=1;
	for(int i=1;i<=n;i++)
		dist[i]=g[i][a];
	for(int k=1;k<n;k++)
	{
		int minal=INF;
		int mp=-1;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&dist[i]<minal)
			{
				mp=i;
				minal=dist[i];
			}
		if(mp<0)
			return;
		ans+=minal;
		vis[mp]=1;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&dist[i]>g[mp][i])
				dist[i]=g[mp][i];
	}
}

int main()
{
	while(cin>>n)
	{
		CLR(vis,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&g[i][j]);
		for(int i=1;i<=n;i++)
			g[i][i]=INF;
		int q;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d %d",&x,&y);
			g[x][y]=g[y][x]=0;
		}
		ans=0;
		prim(1);
		cout<<ans<<endl;
	}

	return 0;
}


/*************************************************************************
	> File Name: hdoj1879.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月28日 星期日 16时18分34秒
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
int n,ans;

void kruskal(int a)
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
	while(cin>>n,n)
	{
		CLR(g,0x3f);
		CLR(vis,0);
		int t=n*(n-1)/2;
		for(int i=0;i<t;i++)
		{
			int x,y,a,f;
			scanf("%d %d %d %d",&x,&y,&a,&f);
			if(a<g[x][y])
				g[x][y]=g[y][x]=a;
			if(f)
				g[x][y]=g[y][x]=0;
		}
		ans=0;
		kruskal(1);
		cout<<ans<<endl;
	}

	return 0;
}


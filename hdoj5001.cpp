/*************************************************************************
	> File Name: hdoj5001.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月13日 星期二 21时22分08秒
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
#define N 55
#define M 10005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

double dp[M][N],ans[N];
vector<int> edge[N];
int n,m,d,t;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&d);
		for(int i=1;i<=n;i++)
			edge[i].clear();
		CLR(ans,0);
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			edge[x].PB(y);
			edge[y].PB(x);
		}
		for(int v=1;v<=n;v++)
		{
			CLR(dp,0);
			for(int i=1;i<=n;i++)
				dp[0][i]=1.0/n;
			ans[v]+=dp[0][v];
			for(int i=0;i<d;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(j==v) continue;
					for(int k=0;k<edge[j].size();k++)
					{
						if(j==edge[j][k]) continue;
						dp[i+1][edge[j][k]]+=(1.0/edge[j].size())*dp[i][j];
					}
				}
				ans[v]+=dp[i+1][v];
			}
		}
		for(int i=1;i<=n;i++)
			printf("%.10lf\n",1.0-ans[i]);
	}

	return 0;
}


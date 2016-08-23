/*************************************************************************
	> File Name: poj1975.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月23日 星期二 11时27分31秒
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

int g[N][N];
int t,n,m;

void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(g[i][k]==1&&g[k][j]==1)
					g[i][j]=1;
				else if(g[i][k]==-1&&g[k][j]==-1)
					g[i][j]=-1;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		CLR(g,0);
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			g[x][y]=1;
			g[y][x]=-1;
		}
		floyd();
		int cnt;
		int t1,t2;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			t1=t2=0;
			for(int j=1;j<=n;j++)
				if(g[i][j]==1)
					t1++;
				else
					if(g[i][j]==-1)
						t2++;
			if(t1>=(n+1)/2||t2>=(n+1)/2)
				cnt++;
		}
		cout<<cnt<<endl;
	}

	return 0;
}


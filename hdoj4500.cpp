/*************************************************************************
	> File Name: hdoj4500.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月01日 星期一 20时20分52秒
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
#define N 21
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dir[4][2]={0,1,0,-1,1,0,-1,0};
int g[N][N];
int maxi,maxj,maxa;
int n,m;

int main()
{
	while(scanf("%d %d",&n,&m),n||m)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&g[i][j]);
		maxa=-INF;
		for(int i=n-1;i>=0;i--)
			for(int j=m-1;j>=0;j--)
			{
				int tmp=0;
				for(int k=0;k<4;k++)
				{
					int ti=i+dir[k][0];
					int tj=j+dir[k][1];
					if(ti>=0&&ti<n&&tj>=0&&tj<m)
						if(g[i][j]*g[ti][tj]<0)
							tmp+=abs(g[ti][tj]);
						else
							tmp-=abs(g[ti][tj]);
				}
				if(tmp>=maxa)
				{
					maxi=i+1;
					maxj=j+1;
					maxa=tmp;
				}
			}
		printf("%d %d %d\n",maxi,maxj,maxa);
	}

	return 0;
}


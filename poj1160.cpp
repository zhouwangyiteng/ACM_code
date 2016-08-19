/*************************************************************************
	> File Name: poj1160.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月19日 星期五 20时26分28秒
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
#define N 305
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int v,p;
int pos[N];
int dp[35][N],cost[N][N];

int main()
{
	while(scanf("%d %d",&v,&p)!=EOF)
	{
		for(int i=1;i<=v;i++)
			scanf("%d",pos+i);
		CLR(cost,0);
		for(int i=1;i<=v;i++)
			for(int j=i;j<=v;j++)
			{
				int m=(i+j)>>1;
				for(int k=i;k<=j;k++)
					cost[i][j]+=abs(pos[k]-pos[m]);
			}
		CLR(dp,0x3f);
		dp[0][0]=0;
		for(int i=0;i<=p;i++)
			for(int j=0;j<=v;j++)
			{
				if(dp[i][j]>=INF) continue;
				for(int k=1;k+j<=v;k++)
					dp[i+1][j+k]=min(dp[i+1][j+k],dp[i][j]+cost[j+1][j+k]);
			}
		cout<<dp[p][v]<<endl;
	}

	return 0;
}


/*************************************************************************
	> File Name: hdoj4501.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月01日 星期一 21时01分37秒
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
#define N 205
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,v1,v2,k;
int a[N],b[N],val[N];
int dp[N][N][10];

int main()
{
	while(scanf("%d %d %d %d",&n,&v1,&v2,&k)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d %d %d",a+i,b+i,val+i);
		CLR(dp,0);
		for(int i=1;i<=n;i++)
			for(int j=v1;j>=0;j--)
				for(int t=v2;t>=0;t--)
					for(int v=k;v>=0;v--)
					{
						int tmp=0;
						if(j-a[i]>=0)
							tmp=max(tmp,dp[j-a[i]][t][v]+val[i]);
						if(t-b[i]>=0)
							tmp=max(tmp,dp[j][t-b[i]][v]+val[i]);
						if(v-1>=0)
							tmp=max(tmp,dp[j][t][v-1]+val[i]);
						dp[j][t][v]=max(tmp,dp[j][t][v]);
					}
		cout<<dp[v1][v2][k]<<endl;
	}

	return 0;
}


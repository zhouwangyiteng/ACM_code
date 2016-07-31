/*************************************************************************
	> File Name: hdoj1176.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月31日 星期日 16时18分13秒
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
#define N 100005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,x,t;
int dp[N][11];
int mtime;

int main()
{
	while(cin>>n,n)
	{
		mtime=-1;
		CLR(dp,0);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&x,&t);
			dp[t][x]++;
			if(mtime<t)
				mtime=t;
		}
		for(int i=mtime-1;i>=0;i--)
		{
			dp[i][0]=max(dp[i+1][0],dp[i+1][1])+dp[i][0];
			for(int j=1;j<10;j++)
				dp[i][j]=max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]))+dp[i][j];
			dp[i][10]=max(dp[i+1][9],dp[i+1][10])+dp[i][10];
		}
		cout<<dp[0][5]<<endl;
	}

	return 0;
}


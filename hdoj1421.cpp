/*************************************************************************
	> File Name: hdoj1421.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月01日 星期一 10时41分36秒
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
#define N 2005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N][N];
int a[N];
int n,k;

int getf(int i,int j)
{
	if(2*j>i)
		return INF;
	if(j==0)
		return 0;
	return dp[i][j];
}

int main()
{
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)
		{
			a[i]=a[i+1]-a[i];
			a[i]*=a[i];
		}
		for(int j=1;j<=k;j++)
			for(int i=2*j;i<=n;i++)
				dp[i][j]=min(getf(i-1,j),getf(i-2,j-1)+a[i-1]);
		cout<<dp[n][k]<<endl;
	}

	return 0;
}


/*************************************************************************
	> File Name: poj3628.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月02日 星期二 20时00分19秒
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
#define N 2000005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N];
int h[25];
int n,b,sum;

int main()
{
	scanf("%d %d",&n,&b);
	sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",h+i);
		sum+=h[i];
	}
	CLR(dp,0);
	for(int i=0;i<n;i++)
		for(int j=sum;j>=h[i];j--)
			dp[j]=max(dp[j],dp[j-h[i]]+h[i]);
	int ans=sum;
	for(int i=b;i<=sum;i++)
		if(dp[i]>=b&&dp[i]-b<ans)
			ans=dp[i]-b;
	cout<<ans<<endl;

	return 0;
}


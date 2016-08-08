/*************************************************************************
	> File Name: hdoj1171.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月08日 星期一 19时34分43秒
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
#define N 1000000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int sum,val,num;
int dp[N];
int a[N];
int tail,n;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	while(cin>>n,n>0)
	{
		tail=sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&val,&num);
			sum+=val*num;
			while(num--)
				a[++tail]=val;
		}
		double p=1.0*sum/2;
		sort(a+1,a+1+tail,cmp);
		CLR(dp,0);
		int maxn=0;
		for(int i=1;i<=tail;i++)
		{
			for(int j=0;j<i;j++)
				if(a[i]+dp[j]<=p)
					dp[i]=max(dp[i],dp[j]+a[i]);
			maxn=max(maxn,dp[i]);
		}
		maxn=max(maxn,sum-maxn);
		printf("%d %d\n",maxn,sum-maxn);
	}

	return 0;
}


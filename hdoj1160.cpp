/*************************************************************************
	> File Name: hdoj1160.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月12日 星期五 21时22分18秒
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
#define N 1005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int w,s,num;
	node(){};
	node(int x,int y,int z):w(x),s(y),num(z){};
};
node a[N];
int p[N];
int dp[N];
int n=0;

bool cmp(node a,node b)
{
	if(a.w==b.w)
		return a.s>b.w;
	else
		return a.w<b.w;
}

void show(int i)
{
	if(i<0)
		return;
	show(p[i]);
	cout<<i<<endl;
}

int main()
{
	CLR(p,-1);
	int x,y;
	n=1;
	while(scanf("%d %d",&x,&y)!=EOF)
	{
		a[n]=node(x,y,n);
		n++;
	}
	sort(a+1,a+n,cmp);
	fill(dp+1,dp+n,1);
	// for(int i=1;i<n;i++)
	// 	cout<<a[i].w<<' '<<a[i].s<<' '<<a[i].num<<' '<<dp[i]<<endl;
	for(int i=1;i<n;i++)
		for(int j=1;j<i;j++)
		{
			if(a[i].w!=a[j].w&&a[i].s<a[j].s&&dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
				p[a[i].num]=a[j].num;
			}	
		}
	int ans=-1;
	int mi;
	// for(int i=1;i<n;i++)
	// 	cout<<p[i]<<' ';
	// cout<<endl;
	for(int i=1;i<n;i++)
		if(dp[i]>=ans)
		{
			ans=dp[i];
			mi=a[i].num;
		}
	cout<<ans<<endl;
	show(mi);

	return 0;
}


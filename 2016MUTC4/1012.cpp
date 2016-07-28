/*************************************************************************
	> File Name: 1012.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月28日 星期四 19时29分43秒
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

int d[N],a[N],ans[N];
int n,m,t,x,y;

void add(int i,int x)
{
	while(i<=n)
	{
		d[i]+=x;
		i+=i&-i;
	}
}

int query(int i)
{
	int s=0;
	while(i>0)
	{
		s+=d[i];
		i-=i&-i;
	}
	return s;
}

int main()
{
	scanf("%d",&t);
	for(int icase=1;icase<=t;icase++)
	{
		CLR(ans,0);
		CLR(d,0);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=n;i>=1;i--)
		{
			add(a[i],1);
			ans[a[i]]=query(a[i])+i-1-min(i,a[i]);
		}
		cout<<"Case #"<<icase<<":";
		for(int i=1;i<=n;i++)
			printf(" %d",ans[i]);
		cout<<endl;
	}

	return 0;
}

 
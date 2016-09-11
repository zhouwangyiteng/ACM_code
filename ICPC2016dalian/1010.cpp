/*************************************************************************
	> File Name: ICPC2016dalian/1010.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月10日 星期六 12时51分47秒
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
#define N 100005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

vector<int> g[N];
map<int,int> mp;
int p[N],a[N],c[N];
int b[N];
int n,u,v,root;
LL k,cnt;

void init()
{
	cnt=0;
	CLR(p,-1);
	for(int i=1;i<=n;i++)
		g[i].clear();
	mp.clear();
	CLR(b,0);
}

int FIND(int x)
{
	while(p[x]>0)
		x=p[x];
	return x;
}

int lowbit(int i)
{
	return i&-i;
}

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=b[i];
		i-=lowbit(i);
	}
	return s;
}

void add(int i,int x)
{
	while(i<=n)
	{
		b[i]+=x;
		i+=lowbit(i);
	}
}

void dfs(int root)
{
	int len=g[root].size();
	int t=upper_bound(c+1,c+1+n,1.0*k/a[root])-c-1;
	cnt+=sum(t);
	add(mp[a[root]],1);
	for(int i=0;i<len;i++)
		dfs(g[root][i]);
	add(mp[a[root]],-1);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %lld",&n,&k);
		init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			c[i]=a[i];
		}
		sort(c+1,c+1+n);
		for(int i=1;i<=n;i++)
			mp[c[i]]=i;
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].PB(v);
			p[v]=u;
		}
		root=FIND(1);
		dfs(root);
		printf("%lld\n",cnt);
	}

	return 0;
}


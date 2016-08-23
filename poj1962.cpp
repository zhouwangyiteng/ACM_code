/*************************************************************************
	> File Name: poj1962.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月23日 星期二 17时18分52秒
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
#define N 20005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int p[N],d[N];
int t,n,x,y;
char ch[2];

int find(int x)
{
	if(x==p[x])
		return x;
	int fx=find(p[x]);
	d[x]+=d[p[x]];
	return p[x]=fx;
}

void Union(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
		return;
	p[x]=x;
	d[fx]=d[x];
	p[x]=y;
	d[x]=abs(x-y)%1000;
}

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			p[i]=i;
			d[i]=0;
		}
		while(scanf("%s",ch))
		{
			if(ch[0]=='O')
				break;
			if(ch[0]=='E')
			{
				scanf("%d",&x);
				find(x);
				printf("%d\n",d[x]);
			}
			if(ch[0]=='I')
			{
				scanf("%d %d",&x,&y);
				Union(x,y);
			}
		}
	}

	return 0;
}


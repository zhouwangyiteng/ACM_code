/*************************************************************************
	> File Name: hdoj1541.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月11日 星期四 19时50分01秒
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
#define N 15005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int b[32005];
int l[N];
int n,nx;
int x[N];

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
	while(i<=nx)
	{
		b[i]+=x;
		i+=lowbit(i);
	}
}


int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		CLR(b,0);
		CLR(l,0);
		nx=0;
		for(int i=0;i<n;i++)
		{
			int y;
			scanf("%d %d",x+i,&y);
			nx=max(x[i],nx)+1;
		}
		for(int i=0;i<n;i++)
		{
			int t=sum(x[i]+1);
			l[t]++;
			add(x[i]+1,1);
		}
		for(int i=0;i<n;i++)
			printf("%d\n",l[i]);
	}

	return 0;
}


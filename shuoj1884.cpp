/*************************************************************************
	> File Name: shuoj1884.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月22日 星期五 15时32分34秒
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
#define INF 0x3f3f3f
#define MAXN 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int d[MAXN+5];
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
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		add(i,a);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
			add(x,y);
		else
			printf("%d\n",query(y)-query(x-1));
	}

	return 0;
}


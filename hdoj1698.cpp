/*************************************************************************
	> File Name: hdoj1698.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月22日 星期五 10时54分44秒
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

struct node
{
	int l,r,c,n;
};

node d[4*MAXN];
int t,n,q;

void init(int i,int j,int k)
{
	d[k].l=i;
	d[k].r=j;
	d[k].c=1;
	if(i==j)
		return;
	int m=(i+j)>>1;
	init(i,m,2*k);
	init(m+1,j,2*k+1);
}

void update(int s,int i,int j,int z)
{
	if(d[s].c==z)
		return;
	if(d[s].l==i&&j==d[s].r)
	{
		d[s].c=z;
		return;
	}
	if(d[s].c!=-1)
	{
		d[2*s].c=d[2*s+1].c=d[s].c;
		d[s].c=-1;
	}
	int m=(d[s].l+d[s].r)>>1;
	if(j<=m)
		update(2*s,i,j,z);
	else if(i>m)
		update(2*s+1,i,j,z);
	else 
	{
		update(2*s,i,m,z);
		update(2*s+1,m+1,j,z);
	}
}

int find(int i)
{
	if(d[i].c!=-1)
		return d[i].c*(d[i].r-d[i].l+1);
	else
		return find(2*i)+find(2*i+1);
}

int main()
{
	cin>>t;
	int icase=0;
	while(t--)
	{
		scanf("%d%d",&n,&q);
		init(1,n,1);
		for(int i=0;i<q;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			update(1,x,y,z);
		}
		printf("Case %d: The total value of the hook is %d.\n",++icase,find(1));
	}
	return 0;
}


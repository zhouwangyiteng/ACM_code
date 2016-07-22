/*************************************************************************
	> File Name: shuoj1885.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月22日 星期五 15时47分52秒
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
	int l,r;
	int n,inc;
};
node d[4*MAXN];
int r[MAXN];
int n,m,t;

void init(int i,int j,int k)
{
	d[k].l=i;
	d[k].r=j;
	d[k].inc=0;
	if(i==j)
	{
		d[k].n=r[i];
		return;
	}
	int m=(i+j)>>1;
	init(i,m,k<<1);
	init(m+1,j,k<<1|1);
	d[k].n=d[k<<1].n+d[k<<1|1].n;
}

void update(int k,int a,int b,int c)
{
	if(d[k].l==a&&d[k].r==b)
	{
		d[k].inc+=c;
		return;
	}
	d[k].n+=(b-a+1)*c;
	int m=(d[k].l+d[k].r)>>1;
	if(b<=m)
		update(k<<1,a,b,c);
	else if(a>m)
		update(k<<1|1,a,b,c);
	else
	{
		update(k<<1,a,m,c);
		update(k<<1|1,m+1,b,c);
	}
}

int query(int k,int i)
{
	if(i==d[k].l&&i==d[k].r)
		return d[k].n+d[k].inc;
	d[k].n+=(d[k].r-d[k].l+1)*d[k].inc;
	int m=(d[k].l+d[k].r)>>1;
	update(k<<1,d[k].l,m,d[k].inc);
	update(k<<1|1,m+1,d[k].r,d[k].inc);
	d[k].inc=0;
	if(i<=m)
		return query(k<<1,i);
	else
		return query(k<<1|1,i);

}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
	init(1,n,1);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&t);
		if(t==1)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			update(1,x,y,z);
		}
		else
		{
			scanf("%d",&t);
			printf("%d\n",query(1,t));  
		}
	}

	return 0;
}


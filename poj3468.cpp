/*************************************************************************
	> File Name: poj3468.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月22日 星期五 11时45分49秒
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
	ll n,inc;
};

node d[4*MAXN];
int r[MAXN];
int n,m;
char q[5];

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
	init(i,m,2*k);
	init(m+1,j,2*k+1);
	d[k].n=d[2*k].n+d[2*k+1].n;
}

void update(int k,int a,int b,ll c)
{
	if(d[k].l==a&&b==d[k].r)
	{
		d[k].inc+=c;
		return;
	}
	d[k].n+=c*(b-a+1);
	int m=(d[k].l+d[k].r)>>1;
	if(b<=m)
		update(k<<1,a,b,c);
	else if(a>m)
		update(2*k+1,a,b,c);
	else
	{
		update(k<<1,a,m,c);
		update(2*k+1,m+1,b,c);
	}
}

ll query(int k,int a,int b)
{
	if(a==d[k].l && b==d[k].r)
		return d[k].n+(b-a+1)*d[k].inc;
	d[k].n+=(d[k].r-d[k].l+1)*d[k].inc;
	int m=(d[k].l+d[k].r)>>1;
	update(k<<1,d[k].l,m,d[k].inc);
	update(k<<1|1,m+1,d[k].r,d[k].inc);
	d[k].inc=0;
	if(b<=m)
		return query(k<<1,a,b);
	else if(a>m)
		return query(k<<1|1,a,b);
	else
		return query(k<<1,a,m)+query(k<<1|1,m+1,b);
}

int main()
{
	cin>>n>>m;
	r[0]=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
	init(1,n,1);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%s",q);
		if(q[0]=='Q')
		{
			scanf("%d%d",&a,&b);
			cout<<query(1,a,b)<<endl;
		}
		else
		{
			scanf("%d%d%d",&a,&b,&c);
			update(1,a,b,c);
		}
	}
	
	return 0;
}


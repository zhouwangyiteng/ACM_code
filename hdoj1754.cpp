/*************************************************************************
	> File Name: hdoj1166.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月21日 星期四 19时00分47秒
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
#define MAXN 200000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int l,r,c;
};

node d[4*MAXN];
int r[MAXN];
int n,m;
char q[5];

void init(int i,int j,int k)
{
	d[k].l=i;
	d[k].r=j;
	if(i==j)
	{
		d[k].c=r[i];
		return;
	}
	int m=(i+j)>>1;
	init(i,m,2*k);
	init(m+1,j,2*k+1);
	d[k].c=max(d[2*k].c,d[2*k+1].c);
}

int query(int s,int i,int j)
{
	if(i==d[s].l && j==d[s].r)
		return d[s].c;
	int m=(d[s].l+d[s].r)>>1;
	if(j<=m)
		return query(2*s,i,j);
	else if(i>m)
		return query(2*s+1,i,j);
	else return max(query(2*s,i,m),query(2*s+1,m+1,j));

}

void update(int s,int i,int j)
{
	if(i==d[s].r&&i==d[s].l)
	{
		d[s].c=j;
		return;
	}
	int m=(d[s].l+d[s].r)>>1;
	if(i<=m)
		update(s<<1,i,j);
	else
		update(2*s+1,i,j);
	d[s].c=max(d[2*s].c,d[2*s+1].c);
}

int main()
{
	while(cin>>n>>m)
	{
		r[0]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&r[i]);
		init(1,n,1);
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%s%d%d",q,&x,&y);
			if(q[0]=='Q')
				cout<<query(1,x,y)<<endl;
			else
				update(1,x,y);
		}
	}
	
	return 0;
}


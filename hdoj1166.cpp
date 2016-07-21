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
#define MAXN 50005
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
int t,n;
char q[10];

void init(int i,int j,int k)
{
	d[k].l=i;d[k].r=j;
	if(i==j)
	{
		d[k].c=r[i];
		return;
	}
	int m=(i+j)>>1;
	init(i,m,2*k);
	init(m+1,j,2*k+1);
	d[k].c=d[2*k].c+d[2*k+1].c;
}

int query(int s,int i,int j)
{
	if(i==d[s].l&&j==d[s].r)
		return d[s].c;
	int m=(d[s].l+d[s].r)>>1;
	if(j<=m)
		return query(2*s,i,j);
	else if(i>m)
		return query(2*s+1,i,j);
	else return query(2*s,i,m)+query(2*s+1,m+1,j);

}

void add(int s,int i,int j)
{
	d[s].c+=j;
	if(d[s].l==d[s].r&&i==d[s].l)
		return;
	int m=(d[s].l+d[s].r)>>1;
	if(i<=m)
		add(s<<1,i,j);
	else
		add(2*s+1,i,j);
}

int main()
{
	int icase=0;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		r[0]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&r[i]);
		init(1,n,1);
		cout<<"Case "<<++icase<<":"<<endl;
		scanf("%s",q);
		int i,j;
		while(strcmp(q,"End")!=0)
		{
			scanf("%d%d",&i,&j);
			if(strcmp(q,"Query")==0)
				cout<<query(1,i,j)<<endl;
			else if(strcmp(q,"Add")==0)
				add(1,i,j);
			else
				add(1,i,-j);
			scanf("%s",q);
		}
	}
	
	return 0;
}


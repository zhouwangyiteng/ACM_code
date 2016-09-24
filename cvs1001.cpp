/*************************************************************************
	> File Name: cvs1001.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月24日 星期六 19时46分55秒
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
#define INF 1<<30
#define N 505
#define M 5005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int u,v,d;
};
node a[M];
int p[N];
int n,m;

int Find(int x)
{
	return p[x]==x?x:p[x]=Find(p[x]);
}

void Union(int x,int y)
{
	int px=Find(x);
	int py=Find(y);
	if(px==py)
		return;
	p[x]=y;
}

void init()
{
	for(int i=0;i<N;i++)
		p[i]=i;
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

bool cmp(node x,node y)
{
	return x.d<y.d;
}

int main()
{
	int mmax,mmin,st,ed;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].d);
	scanf("%d%d",&st,&ed);
	sort(a,a+m,cmp);
	mmax=INF;
	mmin=1;
	for(int i=0;i<m;i++)
	{
		init();
		for(int j=i;j>=0;j--)
		{
			Union(a[j].v,a[j].u);
			if(Find(st)==Find(ed))
			{
				if((mmax*1.0/mmin)>(a[i].d*1.0/a[j].d))
				{
					mmax=a[i].d;
					mmin=a[j].d;
				}
				break;
			}
		}
	}
	int r=gcd(mmax,mmin);
	if(mmax==INF&&mmin==1)
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	mmax/=r;
    mmin/=r;
    if(mmin==1){
        printf("%d\n",mmax);
    }
    else{
        printf("%d/%d\n",mmax,mmin);
    }

	return 0;
}


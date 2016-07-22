/*************************************************************************
	> File Name: hdoj2795.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月22日 星期五 10时18分53秒
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
#define ll long long
#define INF 0x3f3f3f
#define MAXN 200005
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int l,r,c;
};

node d[4*MAXN];
int h,w,n,ans,flag;

void init(int i,int j,int k)
{
	d[k].l=i;
	d[k].r=j;
	if(i==j)
	{
		d[k].c=w;
		return;
	}
	int m=(i+j)>>1;
	init(i,m,2*k);
	init(m+1,j,2*k+1);
	d[k].c=max(d[2*k].c,d[2*k+1].c);
}

void update(int s,int wi)
{
	if(!flag&&d[s].c>=wi)
	{
		if(d[s].l==d[s].r)
		{
			ans=d[s].l;
			d[s].c-=wi;
			flag=1;
			return;
		}
		update(2*s,wi);
		update(2*s+1,wi);
		d[s].c=max(d[2*s].c,d[2*s+1].c);
	}

}

int main()
{
	while(cin>>h>>w>>n)
	{
		if(h>n) h=n;
		init(1,h,1);
		for(int i=0;i<n;i++)
		{
			int wi;
			ans=-1;
			flag=0;
			scanf("%d",&wi);
			update(1,wi);
			printf("%d\n",ans);
		}
	}

	return 0;
}


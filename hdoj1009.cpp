/*************************************************************************
	> File Name: hdoj1009.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月09日 星期二 14时36分25秒
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
#define N 1005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	double rate;
	int j,f;
	node(){};
	node(int val,int num,double r):j(val),f(num),rate(r){};
};

node a[N];
int n,m,val,num;
double ans;

bool cmp(node a,node b)
{
	if(a.rate==b.rate)
		return a.f>b.f;
	else
		return a.rate>b.rate;
}

int main()
{
	while(cin>>m>>n,n!=-1&&m!=-1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&val,&num);
			a[i]=node(val,num,1.0*val/num);
		}
		sort(a,a+n,cmp);
		ans=0;
		int i=0;
		while(m>0&&i<n)
		{
			if(m>=a[i].f)
			{
				ans+=a[i].j;
				m-=a[i].f;
			}
			else
			{
				ans+=m*a[i].rate;
				m=0;
			}
			i++;
		}
		printf("%.3lf\n",ans);
	}

	return 0;
}


/*************************************************************************
	> File Name: shuoj1085.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月08日 星期一 21时15分36秒
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
#define N 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	double l,r;
	node(double x,double y):l(x),r(y){};
	node(){};
};

node a[N],b[N];
int n,m;
double ans;


int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf %lf",&a[i].l,&a[i].r);
	scanf("%d",&m);
	ans=0;
	for(int i=0;i<m;i++)
	{
		scanf("%lf %lf",&b[i].l,&b[i].r);
		for(int j=0;j<n;j++)
			if(a[j].l>=b[i].r||a[j].r<=b[i].l)
				continue;
			else
			{
				double ll=max(a[j].l,b[i].l);
				double rr=min(a[j].r,b[i].r);
				ans+=rr-ll;
			}
	}
	printf("%.3lf\n",ans);

	return 0;
}


/*************************************************************************
	> File Name: hdoj1051.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月01日 星期一 16时59分02秒
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
#define INF 0x3f3f3f3f
#define N 5005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int l,w;
}a[N];
int t,n,ans;

bool cmp(node a,node b)
{
	if(a.l==b.l)
		return a.w>b.w;
	else
		return a.l>b.l;
}

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d %d",&a[i].l,&a[i].w);
		sort(a,a+n,cmp);
		ans=n;
		for(int i=1;i<n;i++)
			for(int j=0;j<i;j++)
				if(a[j].l>=a[i].l&&a[j].w>=a[i].w)
				{
					ans--;
					a[j].l=a[i].l;
					a[j].w=a[i].w;
					a[i].l=0;
					a[i].w=0;
					break;
				}
		cout<<ans<<endl;
	}

	return 0;
}


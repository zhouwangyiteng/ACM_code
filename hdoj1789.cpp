/*************************************************************************
	> File Name: hdoj1789.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月09日 星期二 17时24分53秒
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
	int val,dat;
};

node a[N];
bool vis[N];
int t,n,ans,cnt;

bool cmp(node a,node b)
{
	if(a.val==b.val)
		return a.dat>b.dat;
	else
		return a.val>b.val;
}


int main()
{
	cin>>t;
	while(t--)
	{
		cnt=ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i].dat);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i].val);
			cnt+=a[i].val;
		}
		CLR(vis,0);
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
			for(int j=a[i].dat;j>=1;j--)
				if(!vis[j])
				{
					ans+=a[i].val;
					vis[j]=1;
					break;
				}
		printf("%d\n",cnt-ans);
			
	}

	return 0;
}


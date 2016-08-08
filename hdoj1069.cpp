/*************************************************************************
	> File Name: hdoj1069.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月08日 星期一 16时33分56秒
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
#define N 100
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int x,y,z;
	node(int a=0,int b=0,int c=0):x(a),y(b),z(c){};
};

bool cmp(node a,node b)
{
	if(a.x==b.x)
		return a.y>b.y;
	else
		return a.x>b.x;
}

node box[N];
int dp[N];
int n,a,b,c;
int tail,ans;

int main()
{
	int icase=0;
	while(cin>>n,n)
	{
		tail=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			box[tail++]=node(max(a,b),min(a,b),c);
			box[tail++]=node(max(a,c),min(a,c),b);
			box[tail++]=node(max(b,c),min(b,c),a);
		}
		sort(box,box+tail,cmp);
		for(int i=0;i<tail;i++)
		{
			dp[i]=box[i].z;
			for(int j=0;j<i;j++)
				if(box[i].x<box[j].x&&box[i].y<box[j].y)
					dp[i]=max(dp[i],dp[j]+box[i].z);
		}
		ans=0;
		for(int i=0;i<tail;i++)
			ans=max(ans,dp[i]);
		printf("Case %d: maximum height = %d\n",++icase,ans);
	}

	return 0;
}


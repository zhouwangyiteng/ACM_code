/*************************************************************************
	> File Name: 1011.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月26日 星期二 12时44分38秒
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
#define N 100005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int x,y;
};	
bool cmp (node n1, node n2)
{
	if(n1.x==n2.x)
		return n1.y < n2.y;
	else
		return n1.x < n2.x;
}

int dist(node i,node j)
{
	return abs(i.x-j.x)+abs(i.y-j.y);
}

node q[N];
int t,n,m,d;
set<int> myset;

int main()
{
	cin>>t;
	while(t--)
	{
		int flag=0;
		myset.clear();
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d%d",&q[i].x,&q[i].y);
		for(int i=0;!flag&&i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				d=dist(q[i],q[j]);
				if(myset.find(d)!=myset.end())
				{
					flag=1;
					break;
				}
				else
					myset.insert(d);
			}
		// sort(q,q+n,cmp);
		// for(int i=0;i<=n;i++)
		// 	d[0][i]=0;
		// for(int i=1;i<n;i++)
		// {
		// 	d[1][i]=dist(q[i],q[i-1]);
		// 	if(myset.find(d[1][i])!=myset.end())
		// 	{
		// 		flag=1;
		// 		break;
		// 	}
		// 	else
		// 		myset.insert(d[1][i]);
		// }
		// for(int i=2;i<n;i++)
		// 	for(int j=1;j<=n-i;j++)
		// 	{
		// 		d[i][j]=d[i-1][j]+d[i-1][j+1]-d[i-2][j+1];
		// 		if(myset.find(d[i][j])!=myset.end())
		// 		{
		// 			flag=1;
		// 			break;
		// 		}
		// 		else
		// 			myset.insert(d[i][j]);
		// 	}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}


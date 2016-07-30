/*************************************************************************
	> File Name: hdoj5776.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月30日 星期六 21时43分31秒
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
#define M 5005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int sum[M];
bool vis[M];
int t,n,m;

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&m);
		if(n>=m)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++)
				scanf("%d",&m);
		}
		else
		{
			sum[0]=0;
			CLR(vis,0);
			int flag=1;
			for(int i=1;i<=n;i++)
			{
				scanf("%d",sum+i);
				if(flag)
				{
					sum[i]+=sum[i-1];
					int h=sum[i]%m;
					if(h==0)
					{
						flag=0;
						continue;
					}
					if(vis[h])
						flag=0;
					else
						vis[h]=1;
				}
			}
			if(!flag)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}

	return 0;
}


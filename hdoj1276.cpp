/*************************************************************************
	> File Name: hdoj1276.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月11日 星期四 21时21分21秒
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
#define N 5005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n;
bool vis[N];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		CLR(vis,0);
		int sum=n;
		int flag=1;
		while(sum>3)
		{
			int t=0;
			if(flag)
			{
				flag=0;
				for(int i=1;i<=n;i++)
				{
					if(!vis[i])
					{
						t++;
						if(t%2==0)
						{
							vis[i]=1;
							sum--;
						}
					}
				}
			}
			else
			{
				flag=1;
				for(int i=1;i<=n;i++)
				{
					if(!vis[i])
					{
						t++;
						if(t%3==0)
						{
							vis[i]=1;
							sum--;
						}
					}
				}
			}
		}
		printf("%d",1);
		for(int i=2;i<=n;i++)
			if(!vis[i])
				printf(" %d",i);
		printf("\n");
	}

	return 0;
}


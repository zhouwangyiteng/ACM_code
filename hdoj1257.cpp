/*************************************************************************
	> File Name: hdoj1257.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月07日 星期日 18时46分45秒
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
#define N 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N];
int n,a,j;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int cnt=0;
		CLR(dp,0);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			for(j=0;j<=cnt;j++)
			{
				if(j==cnt)
				{
					dp[cnt]=a;
					cnt++;
					break;
				}
				else
					if(a<=dp[j])
					{
						dp[j]=a;
						break;
					}
			}
			sort(dp,dp+cnt-1);
		}
		cout<<cnt<<endl;

	}

	return 0;
}


/*************************************************************************
	> File Name: poj1050.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月17日 星期三 19时24分22秒
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
#define N 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N][N];
int n;
int ans,mx;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		CLR(a,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
				a[i][j]+=a[i-1][j];
			}
		ans=-INF;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				mx=0;
				for(int k=1;k<=n;k++)
				{
					if(mx<=0)
						mx=a[j][k]-a[i][k];
					else
						mx+=a[j][k]-a[i][k];
					ans=max(ans,mx);
				}
			}
		cout<<ans<<endl;
	}

	return 0;
}


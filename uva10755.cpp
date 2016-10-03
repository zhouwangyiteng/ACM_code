/*************************************************************************
	> File Name: uva10755.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月03日 星期一 07时48分56秒
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
#define N 22
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a,b,c;
int h[N][N][N];
LL p[N];
LL ans;
int tt;

LL maxSum(LL a[],int s,int t)
{
	LL res=0;
	LL ans=-0x3f3f3f3f3f3f3f3f;
	for(int i=s;i<=t;i++)
	{
		if(res<=0)
			res=a[i];
		else
			res+=a[i];
		if(res>ans) ans=res;
	}
	return ans;
}

int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++)
			for(int j=1;j<=b;j++)
				for(int k=1;k<=c;k++)
					scanf("%d",&h[i][j][k]);
		ans=-0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				for(int k=j;k<=b;k++)
					for(int t=i;t<=a;t++)
					{
						CLR(p,0);
						for(int kk=i;kk<=t;kk++)
							for(int kkk=j;kkk<=k;kkk++)
								for(int u=1;u<=c;u++)
									p[u]+=h[kk][kkk][u];
						ans=max(ans,maxSum(p,1,c));
					}
			}
		}
		printf("%lld\n",ans);
		if(tt)
			printf("\n");
	}

	return 0;
}


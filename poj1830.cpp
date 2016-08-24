/*************************************************************************
	> File Name: poj1830.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月24日 星期三 10时17分05秒
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
#define N 35
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N][N],s[N],e[N];
int t,n,x,y;

int guass(int n)
{
	int i,j,k,r;
	i=j=k=r=0;
	for(i=1,j=1;i<=n&&j<=n;j++)
	{
		k=i;
		while(k<=n&&!a[k][j])
			k++;
		if(a[k][j])
		{
			for(r=1;r<=n+1;r++)
				swap(a[i][r],a[k][r]);
			for(r=1;r<=n;r++)
				if(r!=i&&a[r][j])
					for(k=i;k<=n+1;k++)
						a[r][k]^=a[i][k];
			i++;
		}
	}
	for(j=i;j<=n;j++)
		if(a[j][n+1])
			return -1;
	return 1<<(n-i+1);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		CLR(a,0);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",e+i);
			a[i][i]=1;
			a[i][n+1]=s[i]^e[i];
		}
		while(scanf("%d %d",&x,&y),x&&y)
			a[y][x]=1;
		int ans=guass(n);
		if(ans<0)
			printf("Oh,it's impossible~!!\n");
		else
			printf("%d\n",ans);
	}

	return 0;
}


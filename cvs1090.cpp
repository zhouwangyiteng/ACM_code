/*************************************************************************
	> File Name: cvs1090.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月05日 星期一 18时36分04秒
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

int dp[N][N];
int a[N],r[N][N];
int n;

void show(int i,int j)
{
	if(i>j)
		return;
	int k=r[i][j];
	if(i==1&&j==n)
		printf("%d",k);
	else
		printf(" %d",k);
	show(i,k-1);
	show(k+1,j);
}

int main()
{
	scanf("%d",&n);
	CLR(dp,0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		dp[i][i]=a[i];
		r[i][i]=i;
	}
	for(int j=1;j<=n;j++)
		for(int i=j-1;i>0;i--)
			for(int k=i;k<=j;k++)
			{
				int x=dp[i][k-1];
				int y=dp[k+1][j];
				if(x==0)x=1;
				if(y==0)y=1;
				if(dp[i][j]<x*y+a[k])
				{
					dp[i][j]=x*y+a[k];
					r[i][j]=k;
				}
			}
	printf("%d\n",dp[1][n]);
	show(1,n);
	printf("\n");

	return 0;
}


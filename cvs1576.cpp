/*************************************************************************
	> File Name: cvs1576.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月20日 星期二 20时40分17秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int dp[N];
int pre[N];
int n,maxp;

void show(int v)
{
	if(pre[v]==0)
	{
		printf("%d",a[v]);
		return;
	}
	show(pre[v]);
	printf(" %d",a[v]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),dp[i]=1;
	CLR(pre,0);
	maxp=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[j]>a[i])
				if(dp[i]+1>dp[j])
				{
					dp[j]=dp[i]+1;
					pre[j]=i;
					if(j>maxp)
						maxp=j;
				}
	cout<<dp[n]<<endl;
	show(maxp);
	cout<<endl;

	return 0;
}


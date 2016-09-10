/*************************************************************************
	> File Name: cvs1380.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月10日 星期六 10时24分15秒
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
#define N 6005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int p[N],dp[N][2],f[N],vis[N];
int n;

int Find(int i)
{
	while(p[i]>0)
		i=p[i];
	return i;
}

void treedp(int x)
{
	vis[x]=1;
	dp[x][0]=0;
	dp[x][1]=f[x];
	for(int i=1;i<=n;i++)
		if(!vis[i]&&p[i]==x)
		{
			treedp(i);
			dp[x][1]+=dp[i][0];
			dp[x][0]+=max(dp[i][0],dp[i][1]);
		}
}

int main()
{
	scanf("%d",&n);
	CLR(p,-1);
	CLR(vis,0);
	for(int i=1;i<=n;i++)
		scanf("%d",f+i);
	int k,l;
	while(scanf("%d %d",&l,&k),k&&l)
		p[l]=k;
	k=Find(1);
	treedp(k);
	cout<<max(dp[k][0],dp[k][1])<<endl;;

	return 0;
}


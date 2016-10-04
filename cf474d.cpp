/*************************************************************************
	> File Name: cf474d.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月04日 星期二 20时51分50秒
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
#define N 100005
#define M 1000000007
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,k,a,b;
int dp[N],ans[N];

int main()
{
	scanf("%d%d",&n,&k);
	dp[0]=1;
	for(int i=1;i<N;i++)
		dp[i]=(dp[i-1]+(i>=k?dp[i-k]:0))%M;
	ans[0]=0;
	for(int i=1;i<N;i++)
		ans[i]=(ans[i-1]+dp[i])%M;
	while(n--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",(ans[b]-ans[a-1]+M)%M);
	}

	return 0;
}


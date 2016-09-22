/*************************************************************************
	> File Name: cvs2598.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月22日 星期四 20时29分20秒
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
#define N 4005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

char a[N],b[N];
int n,m;
int dp[N][N];

int main()
{
	scanf("%s",a);
	n=strlen(a);
	scanf("%s",b);
	m=strlen(b);
	for(int i=0;i<=n;i++)
		dp[i][0]=i;
	for(int j=0;j<=m;j++)
		dp[0][j]=j;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int d1=dp[i-1][j-1]+(a[i-1]==b[j-1]?0:1);
			int d2=dp[i-1][j]+1;
			int d3=dp[i][j-1]+1;
			dp[i][j]=min(d1,min(d2,d3));
		}
	cout<<dp[n][m]<<endl;

	return 0;
}


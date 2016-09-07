/*************************************************************************
	> File Name: cvs1039.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月06日 星期二 22时31分54秒
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
#define N 200
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N][8];
int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i&&j<=m;j++)
			dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
	cout<<dp[n][m]<<endl;
	return 0;
}


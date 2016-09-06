/*************************************************************************
	> File Name: cvs1220.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月06日 星期二 20时45分02秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N][N],a[N][N];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&a[i][j]);
			dp[i][j]=a[i][j];
		}
	for(int i=n-1;i>0;i--)
		for(int j=1;j<=i;j++)
			dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
	cout<<dp[1][1]<<endl;

	return 0;
}


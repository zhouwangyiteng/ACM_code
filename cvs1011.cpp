/*************************************************************************
	> File Name: cvs1011.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月08日 星期四 10时27分55秒
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
#define N 1005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n;
LL dp[N];

int main()
{
	CLR(dp,0);
	dp[0]=1;
	for(int i=1;i<=1000;i++)
		for(int j=0;j<=i/2;j++)
			dp[i]+=dp[j];
	scanf("%d",&n);
	cout<<dp[n]<<endl;

	return 0;
}


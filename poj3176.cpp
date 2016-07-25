/*************************************************************************
	> File Name: poj3176.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月25日 星期一 15时31分14秒
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
#define ll long long
#define INF 0x3f3f3f3f
#define N 355
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N][N],dp[N][N];
int n;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			cin>>a[i][j];
	for(int j=0;j<n;j++)
		dp[n-1][j]=a[n-1][j];
	for(int i=n-2;i>=0;i--)
		for(int j=0;j<=i;j++)
			dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
	cout<<dp[0][0]<<endl;

	return 0;
}


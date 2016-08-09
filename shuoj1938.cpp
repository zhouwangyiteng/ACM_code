/*************************************************************************
	> File Name: shuoj1938.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月09日 星期二 10时50分59秒
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
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,m,k;
int c[N][N];


int main()
{
	k=1000000007;
	CLR(c,0);
	c[0][0]=1;
	for(int i=1;i<=1000;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
	}
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n",c[n][m]);
	}

	return 0;
}


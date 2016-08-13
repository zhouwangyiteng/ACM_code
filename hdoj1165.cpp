/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-08-13 14:47:18

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
#define N 1000005
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[4][N];
int m,n;

void ack()
{
	int i;
    dp[1][0]=2;
    dp[2][0]=3;
    dp[3][0]=5;
    for(i=1;i<1000005;i++)
    {
        dp[1][i]=i+2;
        dp[2][i]=2*i+3;
        dp[3][i]=2*dp[3][i-1]+3;
    }
}

int main()
{
	ack();
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		printf("%d\n",dp[m][n]);
	}

    return 0;
}



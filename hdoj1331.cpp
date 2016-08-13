/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-08-13 19:20:18

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
#define N 21
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N][N][N];
int a,b,c;

int w(int a,int b,int c)
{
    if(dp[a][b][c]>=0)
        return dp[a][b][c];
    if(a==0||b==0||c==0)
        return 1;
    if(a<b&&b<c)
        return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main()
{
	CLR(dp,-1);
    for(int i=0;i<=20;i++)
        for(int j=0;j<=20;j++)
            for(int k=0;k<=20;k++)
                dp[i][j][k]=w(i,j,k);
    while(scanf("%d %d %d",&a,&b,&c))
    {
        if(a==-1&&b==-1&&c==-1)
            break;
        printf("w(%d, %d, %d) = ",a,b,c);
        if(a<=0||b<=0||c<=0)
            a=b=c=0;
        if(a>20||b>20||c>20)
            a=b=c=20;
        printf("%d\n",dp[a][b][c]);
    }

    return 0;
}


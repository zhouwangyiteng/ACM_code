/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-08-13 18:35:04

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
#define N 35
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

LL dp[N][N];
int n,g;
char ch[N];

int main()
{
    while(scanf("%d",&n),n>0)
    {
        CLR(dp,0);
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
        	scanf("%s",ch);
            for(int j=0;j<n;j++)
            {
                g=(int)(ch[j]-'0');
                if(g>0)
                {
                    int ti=i+g;
                    int tj=j+g;
                    if(ti<n)
                        dp[ti][j]+=dp[i][j];
                    if(tj<n)
                        dp[i][tj]+=dp[i][j];
                }
            }
        }
        printf("%lld\n",dp[n-1][n-1]);
    }

    return 0;
}


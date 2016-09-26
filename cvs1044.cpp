/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-09-26 20:00:25

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
#define N 25
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N],dp[N];
int n,maxlen,cnt;

int main()
{
    n=0;
    while(scanf("%d",&a[++n])!=EOF);
    n--;
    for(int i=1;i<=n;i++)
        dp[i]=1;

    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[i]<=a[j])
                dp[i]=max(dp[i],dp[j]+1);
    maxlen=0;
    for(int i=1;i<=n;i++)
        maxlen=max(maxlen,dp[i]);

    for(int i=1;i<=n;i++)
        dp[i]=1;

    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[i]>a[j])
                dp[i]=max(dp[i],dp[j]+1);
    cnt=0;
    for(int i=1;i<=n;i++)
        cnt=max(cnt,dp[i]);
    printf("%d\n%d",maxlen,cnt);

    return 0;
}


/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-09-16 21:55:56

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
#define M 20005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,v;
int a[N],dp[M];

int main()
{
    scanf("%d",&v);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    CLR(dp,0);
    for(int i=1;i<=n;i++)
        for(int j=v;j>=a[i];j--)
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
    cout<<v-dp[v]<<endl;

    return 0;
}


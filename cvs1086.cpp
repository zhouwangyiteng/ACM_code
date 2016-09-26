/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-09-26 19:36:59

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
#define N 10000000
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

LL com(int n,int r)
{
    if(n-r>r) r=n-r;
    LL i,j,s=1;
    for(i=0,j=1;i<r;++i)
    {
        s*=(n-i);
        for(;j<=r&&s%j==0;++j)
            s/=j;
    }
    return s;
}

int n;

int main()
{
    scanf("%d",&n);
    printf("%lld\n",com(2*n,n)/(n+1));

    return 0;
}


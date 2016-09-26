/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-09-26 20:49:38

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
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N],dp1[N],dp2[N];
int n,maxlen;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        dp1[i]=dp2[i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            if(a[i]>a[j])
                dp1[i]=max(dp1[i],dp1[j]+1);
    }
    for(int i=n-1;i>=1;i--)
    	for(int j=i-1;j<=n;j++)
            if(a[i]>a[j])
                dp2[i]=max(dp2[i],dp2[j]+1);
    maxlen=0;
    for(int i=1;i<=n;i++)
        if(dp1[i]+dp2[i]>maxlen)
            maxlen=dp1[i]+dp2[i];
    cout<<n-maxlen+1<<endl;

    return 0;
}


/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-09-16 22:42:47

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
#define M 1005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,k,ans,x,w[N];
double t;
int v[N],a[N],vis[N];
int dp[M];
map<int,int> mpw;
map<int,int> mpv;

int main()
{
    scanf("%d%d%lf",&n,&k,&t);
    x=(int)(t*10);
    CLR(vis,0);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&t);
        w[i]=(int)(t*10);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",v+i);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",a+i);
        mpw[a[i]]=w[i];
        mpv[a[i]]=v[i];
    }
    ans=0;
    for(int i=1;i<=k;i++)
    {
        int tt;
        scanf("%d",&tt);
        vis[tt]=1;
        x-=mpw[tt];
        ans+=mpv[tt];
    }
    for(int i=1;i<=n;i++)
        if(!vis[a[i]])
        {
        	vis[a[i]]=1;
            for(int j=x;j>=mpw[a[i]];j--)
                dp[j]=max(dp[j],dp[j-mpw[a[i]]]+mpv[a[i]]);
        }
    cout<<ans+dp[x]<<endl;

    return 0;
}


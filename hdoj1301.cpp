/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-08-31 18:56:08

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


int g[N][N],dist[N];
int vis[N];
int n,cnt,ans;

void kruskal(int a)
{
    vis[a]=1;
    for(int i=1;i<=n;i++)
        dist[i]=g[i][a];
    for(int k=1;k<n;k++)
    {
        double minal=INF;
        int mp=-1;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&dist[i]<minal)
            {
                mp=i;
                minal=dist[i];
            }
        if(mp<0)
            return;
        ans+=minal;
        vis[mp]=1;
        cnt++;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&dist[i]>g[mp][i])
                dist[i]=g[mp][i];
    }
}

int main()
{

    while(cin>>n,n)
    {
        CLR(g,0x3f);
        int t;
        char ch;
        for(int i=1;i<n;i++)
        {
        	cin>>ch>>t;
        	for(int j=0;j<t;j++)
        	{
        		cin>>ch;
        		cin>>g[i][ch-'A'+1];
        		g[ch-'A'+1][i]=g[i][ch-'A'+1];
        	}
        }
        CLR(vis,0);
        ans=0;
        cnt=1;
        kruskal(1);
        printf("%d\n",ans);
    }

    return 0;
}
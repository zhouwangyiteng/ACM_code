#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
const int MAXN=110;
const int INF=0x3f3f3f3f;
int P[MAXN],L[MAXN],X[MAXN];
int T[MAXN][MAXN],V[MAXN][MAXN];
int cost[MAXN][MAXN];
int dist[MAXN];
bool vis[MAXN];
void Dijkstra(int n,int start)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
        vis[i]=false;
    }
    dist[start]=0;
    for(int j=0;j<n;j++)
    {
        int k=-1;
        double Min=INF;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&dist[i]<Min)
            {
                Min=dist[i];
                k=i;
            }
        if(k==-1)break;
        vis[k]=true;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&dist[k]+cost[k][i]<dist[i])
                dist[i]=dist[k]+cost[k][i];
    }
}

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&P[i],&L[i],&X[i]);
            for(int j=0;j<X[i];j++)
                scanf("%d%d",&T[i][j],&V[i][j]);
        }
        int ans=INF;

        for(int k=max(0,L[1]-m);k<=L[1];k++)
        {
            for(int i=1;i<=n+1;i++)
            for(int j=1;j<=n+1;j++)
            {
                if(i==j)cost[i][j]=0;
                else cost[i][j]=INF;
            }
            for(int i=1;i<=n;i++)
            {
                if(L[i]>k+m||L[i]<k)continue;
                cost[n+1][i]=P[i];
                for(int j=0;j<X[i];j++)
                {
                    if(L[T[i][j]]>=k && L[T[i][j]]<=k+m)
                        cost[T[i][j]][i]=V[i][j];
                }
            }
            Dijkstra(n+1,n+1);
            ans=min(ans,dist[1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}

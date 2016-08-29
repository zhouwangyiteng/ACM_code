/*************************************************************************

        > Author  : zhouwang
        > Created Time: 2016-08-28 18:56:08

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

struct node
{
    int x,y;
}p[N];

double g[N][N],dist[N];
int vis[N];
int n,cnt;
double ans;

void kruskal(int a)
{
    vis[a]=1;
    for(int i=1;i<=n;i++)
        if(g[a][i]>=10&&g[a][i]<=1000)
            dist[i]=g[i][a];
        else
            dist[i]=INF;
    for(int k=1;k<n;k++)
    {
        double minal=INF;
        int mp=-1;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&dist[i]>=10&&dist[i]<=1000&&dist[i]<minal)
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
            if(!vis[i]&&g[mp][i]>=10&&g[mp][i]<=1000&&dist[i]>g[mp][i])
                dist[i]=g[mp][i];
    }
}

double length(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            scanf("%d %d",&p[i].x,&p[i].y);
        CLR(g,0x3f);
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                g[i][j]=g[j][i]=length(p[i],p[j]);
        CLR(vis,0);
        ans=0;
        cnt=1;
        kruskal(1);
        if(cnt==n)
            printf("%.1lf\n",ans*100);
        else
            cout<<"oh!"<<endl;
    }

    return 0;
}



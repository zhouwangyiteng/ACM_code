/*************************************************************************
	> File Name: hdoj4009.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月02日 星期五 09时36分20秒
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
#define N 1005
#define M 500005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

struct point
{
	int x,y,z;
}p[N];
int n,ans,cx,cy,cz,cnt,ne;
class node{
    public:
    int u,v,next;
    int cost;
};
node edge[M];
int pre[N],id[N],vis[N],head[M];
int in[N];

void addedge(int u, int v,int w)
{
    edge[ne].u = u;
    edge[ne].v = v;
    edge[ne].cost = w;
    edge[ne].next=head[u];
    head[u]=ne++;
}

int Directed_MST(int root)
{
    int res=0,nv=n,i;
    while (1)
    {
        for (i=0;i<nv;i++)
            in[i]=INF;
        for (i=0;i<ne;i++)
        {
            int u=edge[i].u;
            int v=edge[i].v;
            if (edge[i].cost<in[v]&&u!=v)
            {
                pre[v]=u;
                in[v]=edge[i].cost;
            }
        }
        for (i=0;i<nv;i++)
            if (i!=root&&in[i]==INF)
            	return -1;
        int cntnode=0;
        CLR(id,-1);
        CLR(vis,-1);
        in[root]=0;
        for (i=0;i<nv;i++)
        {
            res+=in[i];
            int v=i;
            while (vis[v]!=i&&id[v]==-1&&v!=root)
            {
                vis[v]=i;
                v=pre[v];
            }
            if (v!=root&&id[v]==-1)
            {
                for (int u=pre[v];u!=v;u=pre[u])
                	id[u]=cntnode;
                id[v]=cntnode++;
            }
        }
        if (cntnode==0)
        	break;
        for (i=0;i<nv;i++)
            if (id[i]==-1)
            	id[i]=cntnode++;
        for (i=0;i<ne;i++)
        {
            int v=edge[i].v;
            edge[i].u=id[edge[i].u];
            edge[i].v=id[edge[i].v];
            if (edge[i].u!=edge[i].v)
                edge[i].cost-=in[v];
        }
        nv=cntnode;
        root=id[root];
    }
    return res;
}

int mdist(point a,point b)
{
	int d=abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);
	if(a.z>=b.z)
		return d*cy;
	else
		return d*cy+cz;
}

int main()
{
	while(scanf("%d %d %d %d",&n,&cx,&cy,&cz),n&&cx&&cy&&cz)
	{
		ne=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
			addedge(0,i,cx*p[i].z);
		}
		for(int i=1;i<=n;i++)
		{
			int k,t;
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&t);
				if(t==i)
					continue;
				addedge(i,t,mdist(p[i],p[t]));
			}
		}
		n++;
		ans=Directed_MST(0);
		cout<<ans<<endl;
	}

	return 0;
}

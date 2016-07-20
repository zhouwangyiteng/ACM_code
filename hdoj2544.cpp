#include<cstdio>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
#define MAXN 100+10//?? 
#define MAXM 20000+10//?? 
using namespace std;
int n,m,top,vis[MAXN],dis[MAXN],visit[MAXN],head[MAXN];

struct node {
	int from,to,val,next;
};
node edge[MAXM];

void init()//?????? 
{
	top=0;//??????
	memset(head,-1,sizeof(head));
}

void add(int u,int v,int w)//?????
{
	edge[top].from=u;
	edge[top].to=v;
	edge[top].val=w;
	edge[top].next=head[u];
	head[u]=top++;
}


void spfa(int s)//s???
{
	queue<int>q;//????????
	memset(vis,0,sizeof(vis));
	memset(dis,INF,sizeof(dis));//???? ????????
	vis[s]=1;//????????????
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;//???????????    ????  
		for(int i=head[u];i!=-1;i=edge[i].next)//???u???? ???
		{
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].val)
			{
				dis[v]=dis[u]+edge[i].val;\
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	printf("%d\n",dis[n]);
}

void getmap()
{
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);//???  ???a->b,???b->a; 
	}
	
}

int main()
{
	while(scanf("%d%d",&n,&m),n|m)//n|m????  n==0&&m==0????? 
	{
		init();
		getmap();
		spfa(1);
	
	}
	return 0;
}

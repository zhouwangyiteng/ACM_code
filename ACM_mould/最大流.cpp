int flow[MAXN][MAXN],cap[MAXN][MAXN];
int a[MAXN],p[MAXN];
int m,n;

int maxflow(int s,int t)
{
	queue<int> que;
	CLR(flow,0);
	int f=0;
	while(1)
	{
		CLR(a,0);
		a[s]=INF;
		que.push(s);
		while(!que.empty())
		{
			int u=que.front();
			que.pop();
			for(int v=1;v<=n;v++)
			{
				if(!a[v]&&cap[u][v]>flow[u][v])
				{
					p[v]=u;
					que.push(v);
					a[v]=min(a[u],cap[u][v]-flow[u][v]);
				}
			}
		}
		if(a[t]==0)
			break;
		for(int u=t;u!=s;u=p[u])
		{
			flow[p[u]][u]+=a[t];
			flow[u][p[u]]-=a[t];
		}
		f+=a[t];
	}
	return f;
}

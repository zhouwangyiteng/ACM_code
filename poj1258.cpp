#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 101
#define INF 0x3f3f3f

int n;
bool vis[MAXN];
int dist[MAXN][MAXN];
int lowcost[MAXN];

int prim()
{
	int cnt=0;
	vis[0]=true;
	for(int i=0;i<n;i++)
		lowcost[i]=dist[0][i];
	for(int k=1;k<n;k++)
	{
		int min=INF;
		int v=0;
		for(int i=0;i<n;i++)
			if(lowcost[i]<min&&!vis[i])
			{
				min=lowcost[i];
				v=i;
			}
		cnt+=min;
		vis[v]=true;
		for(int i=0;i<n;i++)
			if(!vis[i]&&lowcost[i]>dist[v][i])
				lowcost[i]=dist[v][i];
	}
	return  cnt;
}

int main()
{
    while(cin>>n)
    {
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&dist[i][j]);
		memset(vis,false,sizeof(vis));
		cout<<prim()<<endl;
	}
    
	return 0;  
}    

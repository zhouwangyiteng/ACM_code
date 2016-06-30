#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 501
#define inf 0x3f3f3f

bool vis[MAXN];
int dist[MAXN][MAXN];
int lowcost[MAXN];

int k,n;

int prim(int dist[][MAXN])
{
	int cnt=-1;
	vis[0]=true;
	for(int i=0;i<n;i++)
		lowcost[i]=dist[0][i];
	for(int k=1;k<n;k++)
	{
		int min=inf;
		int v=0;
		for(int i=0;i<n;i++)
			if(lowcost[i]<min&&!vis[i])
			{
				min=lowcost[i];
				v=i;
			}
		if(min>cnt) cnt=min;
		vis[v]=true;
		for(int i=0;i<n;i++)
			if(!vis[i]&&dist[v][i]<lowcost[i])
				lowcost[i]=dist[v][i];
	}
	return cnt;
}

int main()
{
    cin>>k;
    while(k--)
    {
		scanf("%d",&n);
		memset(vis,false,sizeof(vis));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&dist[i][j]);
		cout<<prim(dist)<<endl;
	}
    
	return 0;  
}    

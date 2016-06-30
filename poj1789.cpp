#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 2001

char str[MAXN][8];
int dist[MAXN][MAXN];
bool vis[MAXN];
int n;

int weight(int i,int j)
{
	int sum=0;
	for(int k=0;k<7;k++)
		if(str[i][k]!=str[j][k])
			sum++;
	return sum;
}

int prim(int prim[][MAXN])
{
	int cnt=0;
	int lowcost[MAXN];
	vis[0]=true;
	for(int i=0;i<n;i++)
		lowcost[i]=dist[0][i];
	for(int k=1;k<n;k++)
	{
		int min=8;
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
			if(!vis[i]&&dist[i][v]<lowcost[i])
				lowcost[i]=dist[i][v];
	}
	return cnt;
}

int main()
{
    while(cin>>n&&n)
    {
		for(int i=0;i<n;i++)
			cin>>str[i];
		memset(vis,false,sizeof(vis));
		memset(dist,0x3f,sizeof(dist));
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
			{
				dist[i][j]=dist[j][i]=weight(i,j);
			}
		cout<<"The highest possible quality is 1/"<<prim(dist)<<"."<<endl;
	}
    
	return 0;  
}    

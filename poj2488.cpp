#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 10
int n,m,t;
int idx[MAXN][MAXN];
int flag[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
bool yes;
struct POS
{
	int x;
	char y;
}path[MAXN*MAXN];

void dfs(int r,int c,int step)
{	
	if(step==n*m) 
	{	
		yes=true;
		return;
	}
	for(int i=0;i<8;i++)
	{
		int nx=r+flag[i][0];
		int ny=c+flag[i][1];
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&idx[nx][ny]==0)
		{
			idx[nx][ny]=1;
			path[step].x=nx+1;
			path[step].y=ny+'A';
			dfs(nx,ny,step+1);
			if(yes) return;
			idx[nx][ny]=0;
		}
	}
}

int main()
{
	cin>>t;
	int icase=0;
	while(t--)
	{
		cin>>n>>m;
		cout<<"Scenario #"<<++icase<<':'<<endl;
		yes=false;
		memset(idx,0,sizeof(idx));
		path[0].x=1;
		path[0].y='A';
		idx[0][0]=1;
		dfs(0,0,1);
		if(yes)
		{
			for(int i=0;i<n*m;i++)
				cout<<path[i].y<<path[i].x;
			cout<<endl<<endl;
		}
	 	else
	 		cout<<"impossible"<<endl<<endl;
	}    
    
	return 0;  
}    

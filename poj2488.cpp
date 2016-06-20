#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>//sortËùÔÚ¿â£¬ÅÅĞòÓÃ
using namespace std;
#define MAXN 10
int n,m,t,top;
int idx[MAXN][MAXN];
int flag[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
bool yes;
struct POS
{
	int y;
	char x;
}path[MAXN*MAXN];

void dfs(int r,int c,int step)
{	
			path[top].y=r+1;
			path[top++].x=c+'A';
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
			dfs(nx,ny,step+1);
			if(yes) return;
			idx[nx][ny]=0;
			top--;
		}
	}
	return;
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
		top=0;
		idx[0][0]=1;
		dfs(0,0,1);
		if(yes)
		{
			for(int i=0;i<top;i++)
				cout<<path[i].x<<path[i].y;
			cout<<endl;
		}
	 	else
	 		cout<<"impossible"<<endl;
 		cout<<endl;
	}    
    
	return 0;  
}    

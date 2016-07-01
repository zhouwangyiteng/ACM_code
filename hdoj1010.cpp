#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 7

char g[MAXN][MAXN];
int n,m,t,di,dj;
bool yes;
int dir[4][2]={0,-1,0,1,1,0,-1,0};

void dfs(int si,int sj,int cnt)
{
	if(si<0||sj<0||si>=n||sj>=m) return;
	if(si==di&&sj==dj&&cnt==t) yes=true;
	if(yes) return;
	int tmp=(t-cnt)-abs(si-di)-abs(sj-dj);
	if(tmp<0||tmp&1) return;
	for(int i=0;i<4;i++)
	{
		int ti=si+dir[i][0];
		int tj=sj+dir[i][1];
		if(g[ti][tj]!='X')
		{
			g[ti][tj]='X';
			dfs(ti,tj,cnt+1);
			g[ti][tj]='.';
		}
	}
}

int main()
{
    while(cin>>n>>m>>t)
    {
		if(n==0&&m==0&&t==0) break;
		yes=false;
		int Xcnt=0,si,sj;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>g[i][j];
				if(g[i][j]=='S') {si=i; sj=j;}
				else if(g[i][j]=='D') {di=i;dj=j;}
				else if(g[i][j]=='X') Xcnt++;
			}
		if(n*m-Xcnt<t)
		{
			cout<<"NO"<<endl;
			continue;
		}
		g[si][sj]='X';
		dfs(si,sj,0);
		if(yes)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
	}
    
	return 0;  
}    

#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 5

int g[MAXN][MAXN];
int n,ans;

bool yes(int si, int sj)
{
	bool res=true;
	for(int j=0;j<n;j++)
	{
		if(j==sj||g[si][j]==0) continue;
		if(g[si][j]==1) res=false;
		else
		{
			if(g[si][j]==2&&j<sj) res=true;
			else 
				if(g[si][j]==2) break;
		}
	}
	if(!res)
		return res;
	for(int i=0;i<n;i++)
	{
		if(i==si||g[i][sj]==0) continue;
		if(g[i][sj]==1) res=false;
		else
		{
			if(g[i][sj]==2&&i<si) res=true;
			else 
				if(g[i][sj]==2) break;
		}
	}
	return res;
}

bool finish()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g[i][j]==0&&yes(i,j))
				return false;
	return true;
}

void dfs(int si,int sj,int cnt)
{
	if(finish())
	{
		if(cnt>ans)
			ans=cnt;
		return;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g[i][j]==0&&yes(i,j)&&i>=0&&i<n&&j>=0&&j<n)
			{
				g[i][j]=1;
				dfs(i,j,cnt+1);
				g[i][j]=0;
			}
}

int main()
{
    while(cin>>n)
    {
		if(n==0) break;
		char ch;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				cin>>ch;
				if(ch=='.')
					g[i][j]=0;
				else if(ch=='X')
					g[i][j]=2;
			}
		ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(g[i][j]==0)
				{
					g[i][j]=1;
					dfs(i,j,1);
					g[i][j]=0;
				}
		cout<<ans<<endl;
	}
    
	return 0;  
}    

#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>//sortËùÔÚ¿â£¬ÅÅĞòÓÃ
using namespace std;
#define MAXN 102
int idx[MAXN][MAXN];
char grid[MAXN][MAXN];
int n, m;
void dfs(int r, int c,int id)
{
	if(r<0||r>=n||c<0||c>=m) return;
	if(idx[r][c]>0||grid[r][c]!='@') return;
	idx[r][c] = id;
	for(int dr=-1;dr<=1;dr++)
		for(int dc=-1;dc<=1;dc++)
			if(dr!=0||dc!=0) dfs(r+dr, c+dc, id);
}
int main()
{
	while(cin>>n>>m)
	{
		int cnt=0;
		if(n==0&&m==0) break;
		memset(idx,0,sizeof(idx));
		for(int i=0;i<n;i++)
			for(int j=0; j<m;j++ )
				cin>>grid[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(idx[i][j]==0&&grid[i][j]=='@')
					dfs(i, j, ++cnt);
		cout<<cnt<<endl;
	}    
    
	return 0;  
}    

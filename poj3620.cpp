#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 101
int n,m,k;
int grid[MAXN][MAXN];
int flag[4][2]={0,1,0,-1,1,0,-1,0};
struct POS
{
	int x,y;
}que[MAXN*MAXN];
int bfs(int r,int c)
{
	int t=0,front=0,rear=0,sum=1;
	grid[r][c]=0;
	que[rear].x=r;
	que[rear++].y=c;
	while(front<rear)
	{
		r=que[front].x;
		c=que[front++].y;
		for(int i=0;i<4;i++)
		{
			int nr=r+flag[i][0];
			int nc=c+flag[i][1];
			if(grid[nr][nc]==1&&nr>0&&nr<=n&&nc>0&&nc<=m)
			{
					grid[nr][nc]=0;
					que[rear].x=nr;
					que[rear++].y=nc;
					sum++;
			}
		}
	}
	return sum;
}

int main()
{
    cin>>n>>m>>k;
    int x,y,max=-1,t;
    memset(grid,0,sizeof(grid));
    while(k--)
    {
		cin>>x>>y;
		grid[x][y]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(grid[i][j]==1)
			{
				t=bfs(i,j);
				if(t>max)
					max=t;
			}
	cout<<max<<endl;
    
	return 0;  
}    

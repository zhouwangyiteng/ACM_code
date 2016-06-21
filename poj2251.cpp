#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 31
int l,r,c;
int flag[6][3]={0,0,1,0,1,0,1,0,0,-1,0,0,0,-1,0,0,0,-1};
char grid[MAXN][MAXN][MAXN];
int idx[MAXN][MAXN][MAXN];
struct prog
{
	int x,y,z,step;
}que[MAXN*MAXN*MAXN];

int main()
{
	bool yes;
	int ans;
	while(cin>>l>>r>>c)
	{
		if(l==0&&r==0&&c==0) break;
		memset(idx,0,sizeof(idx));
		ans=0;
		prog start;
		int i,j,k,s;
		for(i=0;i<l;i++)
			for(j=0;j<r;j++)
				for(k=0;k<c;k++)
				{
					cin>>grid[i][j][k];
					if(grid[i][j][k]=='S')
					{
						idx[i][j][k]=1;
						start.x=i;
						start.y=j;
						start.z=k;
						start.step=0;
					}
				}
		int front=0,rear=0;
		yes=0;
		que[0].x=start.x;
		que[0].y=start.y;
		que[0].z=start.z;
		que[0].step=start.step;
		rear++;
		while(front<rear)
		{
			if(yes) break;
			i=que[front].x;
			j=que[front].y;
			k=que[front].z;
			ans=que[front].step;
			front++;
			for(int iter=0;iter<6;iter++)
			{
				int ni=i+flag[iter][0];
				int nj=j+flag[iter][1];
				int nk=k+flag[iter][2];
				if(ni<0||ni>=l||nj<0||nj>=r||nk<0||nk>=c) continue;
				if(grid[ni][nj][nk]=='#') continue;
				if(grid[ni][nj][nk]=='E')
				{
					ans++;
					yes=true;
					break;
				}
				if(grid[ni][nj][nk]=='.'&&idx[ni][nj][nk]==0)
				{
					idx[ni][nj][nk]=1;
					que[rear].x=ni;
					que[rear].y=nj;
					que[rear].z=nk;
					que[rear].step=ans+1;
					rear++;
				}
			}
		}
		if(yes)
			cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
		else
			cout<<"Trapped!"<<endl;
	}
    
	return 0;  
}    

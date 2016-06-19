#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>//sortËùÔÚ¿â£¬ÅÅÐòÓÃ
using namespace std;
#define MAXN 12
int grid[MAXN][MAXN];

int main()
{
    int r,c,start;
    char ch;
    while(cin>>r>>c>>start)
    {
    	memset(grid,0,sizeof(grid));
		if(r==0&&c==0&&start==0) break;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				cin>>ch;
				switch(ch)
				{
				case 'E':grid[i][j]=-1;break;
				case 'S':grid[i][j]=-2;break;
				case 'W':grid[i][j]=-3;break;
				case 'N':grid[i][j]=-4;
				}
			}
		int i=1,j=start;
		int step=0;
		while(i>0&&i<=r&&j>0&&j<=c&&grid[i][j]<0)
		{
			step++;
			switch(grid[i][j])
			{
			case -1:grid[i][j]=step;j++;break;
			case -2:grid[i][j]=step;i++;break;
			case -3:grid[i][j]=step;j--;break;
			case -4:grid[i][j]=step;i--;
			}
		}
		if(grid[i][j]>0)
		{
			cout<<grid[i][j]-1<<" step(s) before a loop of "<<step-grid[i][j]+1<<" step(s)"<<endl;
		}
		else
		{
			cout<<step<<" step(s) to exit"<<endl;
		}
	}
    
	return 0;  
}    

/*************************************************************************
	> File Name: hdoj1264.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月11日 星期四 14时50分10秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define N 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int g[N][N];
int x1,x2,y1,y2;
int cnt;

int main()
{
	cnt=0;
	CLR(g,0);
	while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2))
	{
		if((x1==-2&&x2==-2&&y1==-2&&y2==-2)||(x1==-1&&x2==-1&&y1==-1&&y2==-1))
		{
			cout<<cnt<<endl;
			if(x1==-2)
				break;
			cnt=0;
			CLR(g,0);
			continue;
		}
		if(x1>x2)
		{
			x1^=x2;
			x2^=x1;
			x1^=x2;
		}
		if(y1>y2)
		{
			y1^=y2;
			y2^=y1;
			y1^=y2;
		}
		for(int i=x1;i<x2;i++)
			for(int j=y1;j<y2;j++)
				if(!g[i][j])
				{
					cnt++;
					g[i][j]=1;
				}
	}


	return 0;
}


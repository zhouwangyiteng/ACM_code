/*************************************************************************
	> File Name: cvs1496.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月10日 星期六 09时06分51秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
using namespace std;
#define X first
#define Y second
#define LL long long
#define INF 0x3f3f3f3f
#define N 1050
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int m[N][N];
int x,y,k;
int dir[5][2][2]={0,0,0,0,-1,0,0,-1,-1,0,0,1,0,-1,1,0,0,1,1,0};

void search(int px,int py,int r0,int r1,int c0,int c1)
{
	if(r0==r1)
		return;
	int mr=(r0+r1+1)/2;
	int mc=(c0+c1+1)/2;
	if(px<mr)
	{
		if(py<mc)
		{
			int t=1;
			printf("%d %d %d\n",mr,mc,t);
			m[mr][mc]=t;
			for(int i=0;i<2;i++)
				m[mr+dir[t][i][0]][mc+dir[t][i][1]]=t;
			search(px,py,r0,mr-1,c0,mc-1);
			search(mr-1,mc,r0,mr-1,mc,c1);
			search(mr,mc-1,mr,r1,c0,mc-1);
			search(mr,mc,mr,r1,mc,c1);
		}
		else
		{
			int t=2;
			printf("%d %d %d\n",mr,mc-1,t);
			m[mr][mc-1]=t;
			for(int i=0;i<2;i++)
				m[mr+dir[t][i][0]][mc-1+dir[t][i][1]]=t;
			search(mr-1,mc-1,r0,mr-1,c0,mc-1);
			search(px,py,r0,mr-1,mc,c1);
			search(mr,mc-1,mr,r1,c0,mc-1);
			search(mr,mc,mr,r1,mc,c1);
		}	
	}
	else
	{
		if(py<mc)
		{
			int t=3;
			printf("%d %d %d\n",mr-1,mc,t);
			m[mr-1][mc]=t;
			for(int i=0;i<2;i++)
				m[mr-1+dir[t][i][0]][mc+dir[t][i][1]]=t;
			search(mr-1,mc-1,r0,mr-1,c0,mc-1);
			search(mr-1,mc,r0,mr-1,mc,c1);
			search(px,py,mr,r1,c0,mc-1);
			search(mr,mc,mr,r1,mc,c1);
		}
		else
		{
			int t=4;
			printf("%d %d %d\n",mr-1,mc-1,t);
			m[mr-1][mc-1]=t;
			for(int i=0;i<2;i++)
				m[mr-1+dir[t][i][0]][mc-1+dir[t][i][1]]=t;
			search(mr-1,mc-1,r0,mr-1,c0,mc-1);
			search(mr-1,mc,r0,mr-1,mc,c1);
			search(mr,mc-1,mr,r1,c0,mc-1);
			search(px,py,mr,r1,mc,c1);
		}
	}

}

int main()
{
	scanf("%d%d%d",&k,&x,&y);
	CLR(m,-1);
	m[x][y]=0;
	search(x,y,1,1<<k,1,1<<k);
	for(int i=1;i<=1<<k;i++)
	{
		for(int j=1;j<=1<<k;j++)
			printf("%d ",m[i][j]);
		cout<<endl;
	}

	return 0;
}


/*************************************************************************
	> File Name: 安卓解锁密码方案数.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月09日 星期五 11时31分07秒
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
#define N 5
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

bool vis[N][N];
int a[10];

bool yes(int i,int j,int x,int y)
{
	if(vis[i][j])
		return 0;
	if(i==x&&abs(j-y)==2&&vis[i][(y+j)/2]==0)
		return 0;
	if(j==y&&abs(i-x)==2&&vis[(i+x)/2][j]==0)
		return 0;
	if(abs(i-x)==2&&abs(j-y)==2&&vis[2][2]==0)
		return 0;
	return 1;
}

void dfs(int x,int y,int step)
{
	a[step]++;
	if(step==9)
		return;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(yes(i,j,x,y))
			{
				vis[i][j]=1;
				dfs(i,j,step+1);
				vis[i][j]=0;
			}
}

int main()
{
	CLR(vis,0);
	CLR(a,0);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			vis[i][j]=1;
			dfs(i,j,1);
			vis[i][j]=0;
		}
	for(int i=1;i<10;i++)
		printf("%d %d\n",i,a[i]);

	return 0;
}


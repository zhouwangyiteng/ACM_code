/*************************************************************************
	> File Name: poj3264.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月29日 星期五 11时20分21秒
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
#define ll long long
#define INF 0x3f3f3f3f
#define N  50005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,q,m;
int MAX[N][20];
int MIN[N][20];

void build()
{
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			if(i+(1<<j)-1<=n)
			{
			 	MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]);
				MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);
			}
}

int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&MAX[i][0]);
		MIN[i][0]=MAX[i][0];
	}
	build();
	for(int i=0;i<q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int k=(int)(log(y-x+1)/log(2));
		printf("%d\n",max(MAX[x][k],MAX[y-(1<<k)+1][k])-min(MIN[x][k],MIN[y-(1<<k)+1][k]));
	}

	return 0;
}


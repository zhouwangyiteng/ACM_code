/*************************************************************************
	> File Name: poj2531.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月29日 星期五 15时51分51秒
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
#define N 25
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int g[N][N];
int s[N];
int n,ans;

void dfs(int site,int sum)
{
	int i;
	s[site]=1;
	int num=sum;
	for(int i=0;i<n;i++)
		if(s[i])
			num-=g[i][site];
		else
			num+=g[i][site];
	ans=max(ans,num);
	if(num>sum)
		for(int i=site+1;i<n;i++)
		{
			dfs(i,num);
			s[i]=0;
		}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&g[i][j]);
		CLR(s,0);
		ans=0;
		dfs(0,0);
		cout<<ans<<endl;
	}

	return 0;
}


/*************************************************************************
	> File Name: cvs1116.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月07日 星期五 19时55分39秒
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
#define N 10
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N][N];
int n;
int d[N];
LL cnt;

void dfs(int v)
{
	if(v>n)
	{
		cnt++;
		return;
	}
	for(int i=1;i<=4;i++)
	{
		bool p=false;
		for(int j=1;j<=n;j++)
			if(a[v][j]&&i==d[j])
			{
				p=true;
				break;
			}
		if(p)
			continue;
		d[v]=i;
		dfs(v+1);
		d[v]=0;
	}
}

int main()
{
	CLR(d,0);
	cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	dfs(1);
	cout<<cnt<<endl;

	return 0;
}


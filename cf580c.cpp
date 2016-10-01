/*************************************************************************
	> File Name: cf580c.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月30日 星期五 21时42分54秒
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
#define N 100005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	vector<int> next;
	int hm;
	int isLeaf;
};
node a[N];
int n,m,cnt,x,y;
int vis[N];

void dfs(int r,int cm)
{
	if(cm>m)
		return;
	if(a[r].isLeaf==1&&r!=1)
	{
		cnt++;
		return;
	}
	for(int i=0;i<a[r].next.size();i++)
	{
		int t=a[r].next[i];
		if(vis[t])
			continue;
		vis[t]=1;
		if(a[t].hm)
			dfs(t,cm+1);
		else
			dfs(t,0);
	}
}

int main()
{
	CLR(vis,0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].hm);
		a[i].isLeaf=0;
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		a[x].next.PB(y);
		a[y].next.PB(x);
		a[x].isLeaf++;
		a[y].isLeaf++;
	}
	cnt=0;
	vis[1]=1;
	dfs(1,a[1].hm);
	cout<<cnt<<endl;

	return 0;
}


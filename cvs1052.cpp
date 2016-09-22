/*************************************************************************
	> File Name: cvs1052.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月22日 星期四 21时54分21秒
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
#define N 105
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int v,t;
}a[N];
int n,cnt;
int vis[N];

bool cmp(node a,node b)
{
	return a.v>b.v;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].t);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].v);
	sort(a+1,a+1+n,cmp);
	cnt=0;
	CLR(vis,0);
	for(int i=1;i<=n;i++)
	{
		int tmp=a[i].t;
		while(vis[tmp]&&tmp>0)
			tmp--;
		if(tmp==0)
			continue;
		cnt+=a[i].v;
		vis[tmp]=1;
	}
	cout<<cnt<<endl;

	return 0;
}


/*************************************************************************
	> File Name: hdoj3177.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月09日 星期二 19时11分50秒
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
#define N 1005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int a,b;
	node(){};
	node(int x,int y):a(x),b(y){};
};

int v,n,t;
node f[N];

bool cmp(node x,node y)
{
	return x.b-x.a>y.b-y.a;
}

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&v,&n);
		for(int i=0;i<n;i++)
			scanf("%d %d",&f[i].a,&f[i].b);
		sort(f,f+n,cmp);
		int flag=1;
		for(int i=0;i<n;i++)
			if(f[i].b>v||f[i].a>v)
			{
				flag=0;
				break;
			}
			else
				v-=f[i].a;
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}


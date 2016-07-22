/*************************************************************************
	> File Name: hdoj1232.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月22日 星期五 21时19分10秒
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
#define INF 0x3f3f3f
#define MAXN 1005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int p[MAXN];
int n,m,ans;

int findp(int i)
{
	while(p[i]>=0)
		i=p[i];
	return i;
}

void Union(int a,int b)
{
	int pa=findp(a);
	int pb=findp(b);
	if(pa==pb)
		return;
	ans--;
	p[pb]=pa;
}

int main()
{
	while(cin>>n,n)
	{
		memset(p,-1,sizeof(p));
		cin>>m;
		ans=n-1;
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		cout<<ans<<endl;
	}

	return 0;
}


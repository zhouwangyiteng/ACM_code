/*************************************************************************
	> File Name: hdoj2844.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月08日 星期一 19时04分09秒
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
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,m,ans;
int v[N],c[N];
int vis[100005],use[100005];

int main()
{
	while(cin>>n>>m,n&&m)
	{
		for(int i=0;i<n;i++)
			scanf("%d",v+i);
		for(int i=0;i<n;i++)
			scanf("%d",c+i);
		ans=0;
		CLR(vis,0);
		vis[0]=1;
		for(int i=0;i<n;i++)
		{
			CLR(use,0);
			for(int j=v[i];j<=m;j++)
				if(!vis[j]&&use[j-v[i]]<c[i]&&vis[j-v[i]])
				{
					use[j]=use[j-v[i]]+1;
					vis[j]=1;
					ans++;
				}
		}
		cout<<ans<<endl;
	}

	return 0;
}


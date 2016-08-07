/*************************************************************************
	> File Name: hdoj2037.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月07日 星期日 21时24分04秒
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
#define N 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

pair<int,int> v[N];
int n;

int main()
{
	while(cin>>n,n)
	{
		for(int i=0;i<n;i++)
		{
			int s,e;
			scanf("%d %d",&s,&e);
			v[i].X=e;
			v[i].Y=s;
		}
		sort(v,v+n);
		int ans=0;
		int t=0;
		for(int i=0;i<n;i++)
			if(t<=v[i].Y)
			{
				ans++;
				t=v[i].X;
			}
		cout<<ans<<endl;
	}

	return 0;
}


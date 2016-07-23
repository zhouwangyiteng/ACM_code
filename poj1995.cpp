/*************************************************************************
	> File Name: poj1995.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月23日 星期六 14时27分00秒
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
#define MAXN 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

ll t,h,a,m,n;
ll ans;

ll pow_mod(ll a,ll n,ll m)
{
	if(a==0)
		return 0;
	if(n==0)
		return 1;
	ll res=1;
	while(n)
	{
		if(n&1)
			res=(res*a)%m;
		a=(a*a)%m;
		n>>=1;
	}
	return res;
}

int main()
{
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>m>>h;
		for(int i=0;i<h;i++)
		{
			scanf("%lld%lld",&a,&n);
			ans+=pow_mod(a,n,m);
		}
		cout<<ans%m<<endl;
	}

	return 0;
}


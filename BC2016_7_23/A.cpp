/*************************************************************************
	> File Name: A.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月23日 星期六 19时11分09秒
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

ll t,n,m,ans;

ll pow(ll a,ll n)
{
	ll res=1;
	while(n)
	{
		if(n&1)
			res=res*a;
		a=a*a;
		n>>=1;
	}
	return res;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		if(m>(int)(log(1.0*n)/log(2.0)+1))
			m=(int)(log(1.0*n)/log(2.0)+1);
		while(m>=0)
		{
			ll tmp=pow(2,m);
			if(tmp<=n)
			{
				ans+=n/tmp;
				n=n%tmp;
			}
			m--;
		}
		cout<<ans<<endl;
	}

	return 0;
}


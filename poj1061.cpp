/*************************************************************************
	> File Name: poj1061.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月17日 星期三 10时57分38秒
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
#define N 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

LL x,y,m,n,l,t,k1,k2;

LL gcd(LL x,LL y)
{
	if(!x||!y)
		return x>y?x:y;
	for(LL t;t=x%y;x=y,y=t);
	return y; 
}	

LL extgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	LL d=extgcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return d;
}

int main()
{
	cin>>x>>y>>m>>n>>l;
	LL a=n-m,c=x-y;
	LL r=gcd(a,l);
	if(c%r)
		cout<<"Impossible"<<endl;
	else
	{
		a/=r;
		l/=r;
		c/=r;
		extgcd(a,l,k1,k2);
		x=c*k1-c*k1/l*l;
		if(x<0)
			x+=l;
		cout<<x<<endl;
	}

	return 0;
}


/*************************************************************************
	> File Name: poj2100.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月23日 星期六 11时31分44秒
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

struct node
{
	ll l,r;
	node(ll l,ll r):l(l),r(r){};
};
queue<node> que;
ll n;

int main()
{
	cin>>n;
	while(!que.empty())
		que.pop();
	ll m=(int)(sqrt(1.0*n)+1);
	ll sum,i,j;
	sum=0;
	i=j=1;
	while(1)
	{
		while(sum<n&&j<m)
		{
			sum+=j*j;
			j++;
		}
		if(sum<n)
			break;
		if(sum==n)
			que.push(node(i,j));
		sum-=i*i;
		i++;
	}
	m=que.size();
	cout<<m<<endl;
	while(!que.empty())
	{
		node p=que.front();
		que.pop();
		cout<<p.r-p.l;
		for(ll i=p.l;i<p.r;i++)
			cout<<' '<<i;
		cout<<endl;
	}

	return 0;
}


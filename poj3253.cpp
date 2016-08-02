/*************************************************************************
	> File Name: poj3253.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月02日 星期二 20时51分48秒
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
#define N 20005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

priority_queue<ll, vector<ll>, greater<ll> > que;
int n,l;


int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&l);
		que.push(l);
	}
	ll ans=0;
	while(que.size()>1)
	{
		int a=que.top();
		que.pop();
		int b=que.top();
		que.pop();
		que.push(a+b);
		ans+=a+b;
	}
	while(!que.empty())
		que.pop();
	cout<<ans<<endl;

	return 0;
}


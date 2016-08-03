/*************************************************************************
	> File Name: shuoj1940.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月03日 星期三 21时27分50秒
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
#define N 1000000007
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,m,t;

ll C(int n,int r)
{
	if(n-r>r) r=n-r;
	int i,j;
	ll s=1;
	for(i=0,j=1;i<r;i++)
	{
		s=s*(n-i);
		for(;j<=r&&s%j==0;j++)
			s/=j;
	}
	return s;
}

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&m);
		cout<<C(n,m)%N<<endl;
	}

	return 0;
}


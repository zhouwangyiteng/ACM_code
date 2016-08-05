/*************************************************************************
	> File Name: hdoj1406.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月05日 星期五 09时57分02秒
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
#define N 10005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int t,n,m;

int main()
{
	CLR(a,0);
	for(int i=2;i<10002;i++)
	{
		int sum=0;
		a[i]=a[i-1];
		for(int j=1;j<i;j++)
			if(i%j==0)
				sum+=j;
		if(sum==i)
			a[i]++;
	}
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&m);
		if(n>m)
		{
			n=n^m;
			m=n^m;
			n=n^m;
		}
		printf("%d\n",a[m]-a[n-1]);
	}

	return 0;
}


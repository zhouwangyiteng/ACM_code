/*************************************************************************
	> File Name: hdoj1050.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月09日 星期二 15时12分57秒
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
#define N 201
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int room[N];
int t,n,l,r,i,ans;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		CLR(room,0);
		ans=0;
		while(n--)
		{
			scanf("%d %d",&l,&r);
			if(l>r)
			{
				l=l^r;
				r=l^r;
				l=l^r;
			}
			if(l&1)
				l++;
			if(r&1)
				r++;
			for(i=l;i<=r;i+=2)
				room[i/2]++;
		}
		for(i=1;i<=200;i++)
			ans=max(ans,room[i]);
		printf("%d\n",10*ans);
	}

	return 0;
}


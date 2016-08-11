/*************************************************************************
	> File Name: hdoj1394.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月11日 星期四 15时49分17秒
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
#define N 5005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N],b[N];
int n;
int ans,tmp;

int lowbit(int i)
{
	return i&-i;
}

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=b[i];
		i-=lowbit(i);
	}
	return s;
}

void add(int i,int x)
{
	while(i<=n)
	{
		b[i]+=x;
		i+=lowbit(i);
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		ans=0;
		CLR(b,0);
		for(int i=n-1;i>=0;i--)
		{
			ans+=sum(a[i]+1);
			add(a[i]+1,1);
		}
		tmp=ans;
		for(int i=0;i<n-1;i++)
		{
			tmp=tmp-a[i]+(n-1-a[i]);
			ans=min(ans,tmp);
		}
		cout<<ans<<endl;
	}

	return 0;
}


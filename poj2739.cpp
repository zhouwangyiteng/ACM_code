/*************************************************************************
	> File Name: poj2739.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月23日 星期六 11时06分30秒
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
#define MAXN 10005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int prime[MAXN];
bool isPrime[MAXN];
int n,m;

int getPrime(int n)
{
	int ans=0;
	for(int i=2;i<=n;i++)
		isPrime[i]=true;
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(isPrime[i])
		{
			prime[ans++]=i;
			for(int j=2*i;j<=n;j+=i)
				isPrime[j]=false;
		}
	}
	return ans;
}

int main()
{
	m=getPrime(MAXN);
	while(scanf("%d",&n)&&n)
	{
		int t;
		for(int i=0;i<m;i++)
			if(prime[i]>n)
			{
				t=i;
				break;
			}
		int ans,i,j,sum;
		ans=i=j=sum=0;
		while(1)
		{
			while(j<t&&sum<n)
				sum+=prime[j++];
			if(sum<n)
				break;
			if(sum==n)
				ans++;
			sum-=prime[i++];
		}
		printf("%d\n",ans);
	}

	return 0;
}


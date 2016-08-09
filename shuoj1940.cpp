/*************************************************************************
	> File Name: shuoj1940.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月09日 星期二 11时22分51秒
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

int n,m,k;
int prime[3400],isPrime[N];
int tail;
LL ans;

void sieve()
{
	tail=0;
	CLR(isPrime,0);
	for(int i=2;i<N;i++)
		if(!isPrime[i])
		{
			prime[tail++]=i;
			for(int j=2*i;j<N;j+=i)
				isPrime[j]=1;
		}
}

LL POW(int a,int n,int k)
{
	LL res=1;
	a%=k;
	while(n)
	{
		if(n&1)
			res=(res*a)%k;
		a=(a*a)%k;
		n>>=1;
	}
	return res;
}

int main()
{
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&k);
		int j=0;
		ans=1;
		while(prime[j]<=n)
		{
			int a[]={n,m,n-m};
			int b[]={0,0,0};
			for(int i=0;i<3;i++)
			{
				while(a[i]>0)
				{
					a[i]/=prime[j];
					b[i]+=a[i];
				}
			}
			ans=(ans*POW(prime[j],b[0]-b[1]-b[2],k))%k;
			j++;
		}
		cout<<ans<<endl;
	}


	return 0;
}




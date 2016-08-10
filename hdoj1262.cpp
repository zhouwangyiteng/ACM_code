/*************************************************************************
	> File Name: hdoj1262.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月10日 星期三 21时56分13秒
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
#define N 10001
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int isPrime[N];
int n;

void sieve()
{
	CLR(isPrime,0);
	isPrime[0]=isPrime[1]=1;
	for(int i=2;i<N;i++)
		if(!isPrime[i])
			for(int j=i*2;j<N;j+=i)
				isPrime[j]=1;
}

int main()
{
	sieve();
	while(cin>>n)
	{
		int mid=n/2;
		for(int i=mid;i>=2;i--)
			if(!isPrime[i]&&!isPrime[n-i])
			{
				printf("%d %d\n",i,n-i);
				break;
			}
	}

	return 0;
}


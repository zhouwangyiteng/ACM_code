/*************************************************************************
	> File Name: shuoj1023.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月08日 星期一 20时59分41秒
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

int isPrime[N];
int n;

int main()
{
	cin>>n;
	CLR(isPrime,0);
	for(int i=2;i<=n;i++)
	{
		if(!isPrime[i])
		{
			printf("%d\n",i);
			for(int j=i*2;j<=n;j+=i)
				isPrime[j]=1;
		}
	}

	return 0;
}


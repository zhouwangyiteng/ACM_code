/*************************************************************************
	> File Name: hdoj1005.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月10日 星期三 16时48分45秒
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

int a,b,n;
int f[N];

int main()
{
	int i;
	while(cin>>a>>b>>n,a&&b&&n)
	{
		f[1]=f[2]=1;
		int flag=0;
		for(i=3;i<N;i++)
		{
			f[i]=(a*f[i-1]+b*f[i-2])%7;
			if(f[i]==1&&f[i-1]==1)
				break;
			if(f[i]==0&&f[i-1]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			cout<<0<<endl;
			continue;
		}
		if(i>n)
		{
			cout<<f[n]<<endl;
			continue;
		}
		i-=2;
		n%=i;
		if(n==0)
			n=i;
		cout<<f[n]<<endl;
	}

	return 0;
}


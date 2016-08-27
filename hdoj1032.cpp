/*************************************************************************
	> File Name: hdoj1032.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月27日 星期六 16时30分18秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a,b,ans;

int main()
{
	while(cin>>a>>b)
	{
		int ta=a;
		int tb=b;
		if(a>b)
		{
			a^=b;
			b^=a;
			a^=b;
		}
		ans=0;
		for(int i=a;i<=b;i++)
		{
			int n=i;
			int sum=1;
			while(n-1)
			{
				if(n&1)
					n=3*n+1;
				else
					n/=2;
				sum++;
			}
			ans=max(sum,ans);
		}
		printf("%d %d %d\n",ta,tb,ans);
	}

	return 0;
}


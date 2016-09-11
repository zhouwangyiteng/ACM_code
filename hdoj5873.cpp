/*************************************************************************
	> File Name: hdoj5873.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月11日 星期日 08时40分39秒
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
#define N 20005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N],sum[N];
int n,m;


int main()
{
	while(scanf("%d",&m)!=EOF)
	{
		while(m--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				scanf("%d",a+i);
			sort(a+1,a+n+1);
			sum[1]=a[1];
			for(int i=2;i<=n;i++)
				sum[i]=sum[i-1]+a[i];
			int f=1;
			for(int i=1;i<n;i++)
				if(sum[i]<i*(i-1))
				{
					f=0;
					break;
				}
			if(sum[n]!=n*(n-1))
				f=0;
			if(f)
				printf("T\n");
			else
				printf("F\n");
		}
	}

	return 0;
}


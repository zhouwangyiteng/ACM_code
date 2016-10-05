/*************************************************************************
	> File Name: hdoj5914.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月05日 星期三 13时46分58秒
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
#define N 25
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int t,n;
int a,b;
int f[N];

int main()
{
	fill(f,f+N,1);
	a=1;b=1;
	while(b<20)
	{
		f[b]=0;
		t=b;
		b=a+b;
		a=t;
	}
	f[0]=0;
	for(int i=1;i<=20;i++)
		f[i]+=f[i-1];
	scanf("%d",&t);
	int icase=0;
	while(t--)
	{
		scanf("%d",&n);
		printf("Case #%d: %d\n",++icase,f[n]);
	}

	return 0;
}


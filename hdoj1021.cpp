/*************************************************************************
	> File Name: hdoj1021.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月26日 星期五 21时35分57秒
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
#define N 1000005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

short a[N];
int n;

void init()
{
	CLR(a,0);
	a[0]=7%3;
	a[1]=11%3;
	for(int i=2;i<1000000;i++)
		a[i]=(a[i-1]+a[i-2])%3;
}

int main()
{
	init();
	while(scanf("%d",&n)!=EOF)
	{
		if(!a[n])
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}


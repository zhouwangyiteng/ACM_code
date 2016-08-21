/*************************************************************************
	> File Name: poj2081.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月21日 星期日 16时41分08秒
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
#define N 500005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int n;
bool hash[10000000];

int main()
{
	a[0]=0;
	CLR(hash,0);
	hash[0]=true;
	for(int i=1;i<N;i++)
	{
		int t=a[i-1]-i;
		if(t>0&&!hash[t])
			a[i]=t;
		else
			a[i]=a[i-1]+i;
		hash[a[i]]=true;
	}
	while(scanf("%d",&n),n>=0)
	{
		printf("%d\n",a[n]);
	}

	return 0;
}


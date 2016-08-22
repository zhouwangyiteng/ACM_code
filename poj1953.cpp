/*************************************************************************
	> File Name: poj1953.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月22日 星期一 15时16分57秒
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
#define N 50
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

LL a[N];
int n;

int main()
{
	a[1]=2;
	a[2]=3;
	for(int i=3;i<=45;i++)
		a[i]=a[i-1]+a[i-2];
	int t;
	cin>>t;
	for(int icase=1;icase<=t;icase++)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n%lld\n\n",icase,a[n]);
	}

	return 0;
}


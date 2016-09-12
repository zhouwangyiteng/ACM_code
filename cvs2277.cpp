/*************************************************************************
	> File Name: cvs2277.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月12日 星期一 21时16分26秒
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
#define N 105
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

LL a[N];
int n;

int main()
{
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=90;i++)
		a[i]=a[i-1]+a[i-2];
	scanf("%d",&n);
	printf("%lld\n",a[n]);

	return 0;
}


/*************************************************************************
	> File Name: poj1958.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月22日 星期一 15时31分26秒
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
#define N 15
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];

int main()
{
	CLR(a,0x3f);
	a[1]=1;
	a[2]=3;
	for(int i=3;i<=12;i++)
	{
		for(int k=1;k<i;k++)
			a[i]=min(a[i],(int)(2*a[i-k]+pow(2.0,k)-1));
	}
	for(int i=1;i<=12;i++)
		printf("%d\n",a[i]);

	return 0;
}


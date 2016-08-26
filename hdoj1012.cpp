/*************************************************************************
	> File Name: hdoj1012.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月26日 星期五 19时56分10秒
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

LL a[10];

LL f(int n)
{
	if(a[n]>0)
		return a[n];
	else
		return n*f(n-1);
} 

int main()
{
	CLR(a,-1);
	a[0]=1;
	printf("n e\n- -----------\n");
	double e=0;
	printf("0 1\n1 2\n2 2.5\n");
	for(int i=0;i<10;i++)
	{
		e+=1.0/(f(i));
		if(i>2)
			printf("%d %.9lf\n",i,e);
	}

	return 0;
}


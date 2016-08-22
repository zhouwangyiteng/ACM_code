/*************************************************************************
	> File Name: shuoj1148.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月22日 星期一 21时34分25秒
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

int a[N];
int n;

bool cmp(int a,int b)
{
	return abs(a)>abs(b);
}

int main()
{
	while(scanf("%d",&n),n)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n,cmp);
		cout<<a[0];
		for(int i=1;i<n;i++)
			printf(" %d",a[i]);
		cout<<endl;
	}

	return 0;
}


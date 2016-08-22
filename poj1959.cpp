/*************************************************************************
	> File Name: poj1959.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月22日 星期一 20时19分15秒
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
#define M 64
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int n,t;

void init()
{
	for(int i=0;i<=20;i++)
	{
		a[i]=i;
		a[i+20]=2*i;
		a[i+40]=3*i;
	}
	a[61]=25;
	a[62]=50;
}

int main()
{
	init();
	cin>>t;
	for(int icase=1;icase<=t;icase++)
	{
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<63;i++)
			for(int j=i;j<63;j++)
				for(int k=j;k<63;k++)
					if(a[i]+a[j]+a[k]==n)
						sum++;
		printf("Scenario #%d:\n%d\n\n",icase,sum);
	}

	return 0;
}


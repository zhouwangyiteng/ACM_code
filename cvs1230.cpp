/*************************************************************************
	> File Name: cvs1230.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月25日 星期日 09时34分56秒
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
#define N 100000005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

bool hash[N];
int n,m,t;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		hash[t]=1;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&t);
		if(hash[t])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}


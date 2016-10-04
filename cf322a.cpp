/*************************************************************************
	> File Name: cf322a.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月04日 星期二 21时13分20秒
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

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",n+m-1);
	for(int i=1;i<=m;i++)
		printf("%d %d\n",1,i);
	for(int i=2;i<=n;i++)
		printf("%d %d\n",i,m);

	return 0;
}


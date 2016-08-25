/*************************************************************************
	> File Name: hdoj1729.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月25日 星期四 16时04分47秒
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

int sg(int c,int s)
{
	int t=sqrt(s);
	while(t*t+t>=s) t--;
	if(c>t)
		return s-c;
	else
		return sg(c,t);
}

int main()
{
	int n,c,s,icase=0;
	int ans;
	while(scanf("%d",&n),n)
	{
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&s,&c);
			ans^=sg(c,s);
		}
		printf("Case %d:\n",++icase);
		if(ans)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}


/*************************************************************************
	> File Name: hdoj1719.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月14日 星期日 21时40分16秒
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
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

bool flag;
int n;

bool solve(int n)
{
	n++;
	while(n%2==0)
		n/=2;
	while(n%3==0)
		n/=3;
	if(n==1)
		return true;
	else
		return false;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		flag=1;
		if(n==0)
			flag=0;
		else 
			if(n>3)
				flag=solve(n);
		if(flag)
			printf("YES!\n");
		else
			printf("NO!\n");

	}

	return 0;
}


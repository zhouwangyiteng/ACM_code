/*************************************************************************
	> File Name: hdoj1556.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月19日 星期一 19时00分04秒
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
#define N 100005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int b[N];
int n,t,x,y;

int lowbit(int i)
{
	return i&-i;
}

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=b[i];
		i-=lowbit(i);
	}
	return s;
}

void add(int i,int x)
{
	while(i<=n)
	{
		b[i]+=x;
		i+=lowbit(i);
	}
}

int main()
{
	while(scanf("%d",&n),n)
	{
		CLR(b,0);
		t=n;
		while(t--)
		{
			scanf("%d%d",&x,&y);
			add(x,1);
			add(y+1,-1);
		}
		for(int i=1;i<=n;i++)
		{
			printf("%d",sum(i));
			if(i==n)
				printf("\n");
			else
				printf(" ");
		}
	}

	return 0;
}


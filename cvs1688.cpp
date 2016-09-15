/*************************************************************************
	> File Name: cvs1688.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月15日 星期四 10时07分53秒
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

int a[N],b[N];
int n;
LL cnt;

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
	while(i<=N)
	{
		b[i]+=x;
		i+=lowbit(i);
	}
}

int main()
{
	CLR(b,0);
	cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=n;i>0;i--)
	{
		add(a[i],1);
		cnt+=sum(a[i]-1);
	}
	cout<<cnt<<endl;

	return 0;
}


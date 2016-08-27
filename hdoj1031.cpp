/*************************************************************************
	> File Name: hdoj1031.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月27日 星期六 15时34分17秒
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
#define N 1000000
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	double cnt;
	int num;
}a[N];
int b[N];
int n,m,k;
double t;

bool cmp(node a,node b)
{
	if(a.cnt==b.cnt)
		return a.num<b.num;
	else
		return a.cnt>b.cnt;
}

int main()
{
	while(cin>>n>>m>>k)
	{
		for(int i=0;i<m;i++)
		{
			a[i].cnt=0;
			a[i].num=i+1;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf("%lf",&t);
				a[j].cnt+=t;
			}
		sort(a,a+m,cmp);
		for(int i=0;i<k;i++)
			b[i]=a[i].num;
		sort(b,b+k);
		printf("%d",b[k-1]);
		for(int i=k-2;i>=0;i--)
			printf(" %d",b[i]);
		printf("\n");
	}

	return 0;
}


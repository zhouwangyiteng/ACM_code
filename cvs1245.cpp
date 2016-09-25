/*************************************************************************
	> File Name: cvs1245.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月25日 星期日 09时56分15秒
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

int n;
int a[N],b[N],c[N*30],cnt;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	sort(b+1,b+1+n);
	cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;i*j<=n;j++)
			c[cnt++]=a[i]+b[j];
	sort(c,c+cnt);
	printf("%d",c[0]);
	for(int i=1;i<n;i++)
		printf(" %d",c[i]);
	printf("\n");


	return 0;
}


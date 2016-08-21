/*************************************************************************
	> File Name: poj2181.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月21日 星期日 15时20分39秒
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
#define N 150005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int n;

int main()
{
	scanf("%d",&n);
	a[0]=0;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	a[n+1]=0;
	int p=0;
	LL ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]>=a[i-1]&&a[i]>=a[i+1]&&!p)
		{
			ans+=a[i];
			p=1;
		}
		else if(a[i]<=a[i-1]&&a[i]<=a[i+1]&&p)
		{
			ans-=a[i];
			p=0;
		}
	printf("%lld\n",ans);

	return 0;
}


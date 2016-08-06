#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define X first
#define Y second
#define LL long long
#define INF 0x3f3f3f
#define N 1000005
#define MD(X,Y) ((X)%(Y)+(Y))%(Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int h,n,m;
LL sum[N];

int find(int l,int r)
{
	while(1)
	{
		int mid=(l+r)/2;
		int mm=upper_bound(a,a+n-1,mid)-a;
		LL tmp=sum[mm]-mid*(n-mm);
		if(tmp==m)
			return mid;
		else 
			if(tmp>m)
				l=mid+1;
			else
			 	r=mid;
	}
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		CLR(sum,0);
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		sum[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--)
			sum[i]+=sum[i+1]+a[i];
		printf("%d\n",find(a[0],a[n-1]));
	}

	return 0;
}


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
#define INF 0x3f3f3f
#define N 105
#define M 300005
#define MD(X,Y) ((X)%(Y)+(Y))%(Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[4];
int a[N];
int n,m;

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		CLR(dp,0);
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		int MAX=-1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			if(i!=j)
				for(int k=0;k<n;k++)
				if(k!=j&&k!=i)
				{
					int tmp=a[i]+a[j]+a[k];
					if(tmp>MAX&&tmp<=m)
						MAX=tmp;
				}
		cout<<MAX<<endl;
	}

	return 0;
}


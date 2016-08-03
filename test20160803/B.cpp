#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;
#define INF 0x3f3f3f3f
#define N 105
#define CLR(a,x) memset(a,x,sizeof(a))
#define lowbit(x) (x&-x) 

int hdp[N],ldp[N],a[N];
int n;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		int ans=0;
		CLR(hdp,0);
		CLR(ldp,0);
		for(int i=0;i<n;i++)
		{
			hdp[i]=1;
			for(int j=0;j<i;j++)
				if(a[i]>a[j])
					hdp[i]=max(hdp[i],hdp[j]+1);
		}
		for(int i=n-1;i>=0;i--)
		{
			ldp[i]=1;
			for(int j=n-1;j>i;j--)
				if(a[j]<a[i])
					ldp[i]=max(ldp[i],ldp[j]+1);
		}
		for(int i=0;i<n;i++)
			ans=max(ans,hdp[i]+ldp[i]);
		cout<<n-ans+1<<endl;
	}
	
	return 0;
}


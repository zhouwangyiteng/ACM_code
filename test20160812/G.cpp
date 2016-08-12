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
#include <fstream>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define CLR(a,x) memset(a,x,sizeof(a))
#define LL long long
#define INF 0X3FFFF
#define N 1000005
#define M 1000000
using namespace std;

int a[N],sum[N];
int n,cnt;

int dfs(int n)
{
	while(a[n]==0)
	{
		n--; 
	}
	if(n==0)
		return 0;
	int t1,t2;
	t1=dfs(n-1)+sum[n];
	for(int i=1;i<n;i++)
		a[i]^=1;
	t2=dfs(n-1)+1;
	for(int i=1;i<n;i++)
		a[i]^=1;
	return min(t1,t2);
}

int main()
{
	a[0]=1;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		CLR(sum,0);
		cnt=0;
		int flag=-1;
		for(int i=1;i<=n;i++)
		{
			char ch;
			scanf("%c",&ch);
			if(ch=='A')
			{
				if(flag==1||flag==-1)
				{
					cnt++;
					a[cnt]=0;
					flag=0;
					sum[cnt]=1;
				}
				else
					sum[cnt]++;
			}
			else
			{
				if(flag==0||flag==-1)
				{
					cnt++;
					a[cnt]=1;
					flag=1;
					sum[cnt]=1;
				}
				else
					sum[cnt]++;
			}
		}	
		int ans=dfs(cnt);
		printf("%d\n",ans);
	}
	
	return 0;
}


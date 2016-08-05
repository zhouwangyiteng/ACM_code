/*************************************************************************
	> File Name: hdoj1422.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月05日 星期五 15时44分16秒
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
#define ll long long
#define INF 0x3f3f3f3f
#define N 100005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[2*N],dp[2*N];
int n,i,j,sum,ans;

int main()
{
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
			int w,l;
			scanf("%d %d",&w,&l);
			a[i]=w-l;
			a[i+n]=a[i];
		}
		dp[0]=0;
		n<<=1;
		sum=ans=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(sum>=0)
				dp[i]=dp[i-1]+1;
			else 
			{
				if(a[i]>=0)
					dp[i]=1;
				else
					dp[i]=0;
				sum=0;
			}
			ans=max(ans,dp[i]);
		}
		if(ans>n>>1)
			ans=n>>1;
		cout<<ans<<endl;
	}

	return 0;
}


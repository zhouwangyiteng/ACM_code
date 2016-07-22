/*************************************************************************
	> File Name: hdoj2546.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月22日 星期五 19时07分48秒
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
#define INF 0x3f3f3f
#define MAXN 1005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[2*MAXN];
int w[MAXN];
int n,m;

int main()
{
	while(cin>>n,n)
	{
		int cnt=0,pos=-1,imax=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
			cnt+=w[i];
			if(w[i]>imax)
			{
				pos=i;
				imax=w[i];
			}
		}
		cin>>m;
		if(m<5)
			cout<<m<<endl;
		else if(cnt-imax<=m-5)
			cout<<m-cnt<<endl;
		else
		{
			memset(dp,0,sizeof(dp));
			if(pos!=n)
			{
				int tmp=w[n];
				w[n]=w[pos];
				w[pos]=tmp;
			}
			for(int i=1;i<n;i++)
				for(int v=m-5;v>=w[i];v--)
					dp[v]=max(dp[v],dp[v-w[i]]+w[i]);
			cout<<m-dp[m-5]-imax<<endl;
		}
	}

	return 0;
}


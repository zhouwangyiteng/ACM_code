/*************************************************************************
	> File Name: poj3342.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月03日 星期六 13时43分01秒
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
#define N 205
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int vis[N];
int p[N];
int dp[N][2],dup[N][2];
map<string,int> mp;
string str1,str2;
int n;

void treedp(int root)
{
	vis[root]=1;
	dup[root][0]=dup[root][1]=1;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&p[i]==root)
		{
			treedp(i);
			dp[root][1]+=dp[i][0];
			dp[root][0]+=max(dp[i][0],dp[i][1]);
			if(dp[i][0]>dp[i][1] && dup[i][0]==0) 
				dup[root][0]=0;
        	else if(dp[i][1]>dp[i][0] && dup[i][1]==0) 
        		dup[root][0]=0;
        	else if(dp[i][0]==dp[i][1]) 
        		dup[root][0]=0;
        	if(dup[i][0]==0) 
        		dup[root][1]=0;
		}
}

int main()
{
	while(scanf("%d",&n),n)
	{
		mp.clear();
		CLR(p,-1);
		cin>>str1;
		int tmp=1;
		mp[str1]=1;
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>str1>>str2;
			if(!mp[str1])
				mp[str1]=++tmp;
			a=mp[str1];
			if(!mp[str2])
				mp[str2]=++tmp;
			b=mp[str2];
			p[a]=b;
		}
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=0;
			dp[i][1]=1;
		}
		CLR(vis,0);
		treedp(1);
		if(dp[1][0]>dp[1][1] && dup[1][0]==1) 
			printf("%d Yes\n",dp[1][0]);
        else if(dp[1][1]>dp[1][0] && dup[1][1]==1) 
        	printf("%d Yes\n",dp[1][1]);
        else printf("%d No\n",max(dp[1][0],dp[1][1]));
	}

	return 0;
}


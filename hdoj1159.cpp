/*************************************************************************
	> File Name: hdoj1159.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月12日 星期五 20时51分14秒
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
#define N 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

char str1[N],str2[N];
int len1,len2;
int dp[N][N];

int main()
{
	while(scanf("%s %s",str1,str2)!=EOF)
	{
		len1=strlen(str1);
		len2=strlen(str2);
		CLR(dp,0);
		int ans=-1;
		for(int i=0;i<len1;i++)
			for(int j=0;j<len2;j++)
			{
				if(str1[i]==str2[j])
					dp[i+1][j+1]=dp[i][j]+1;
				else
					dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
				ans=max(ans,dp[i+1][j+1]);
			}
		cout<<ans<<endl;
	}

	return 0;
}


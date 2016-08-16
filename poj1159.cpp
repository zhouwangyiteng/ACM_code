/*************************************************************************
	> File Name: poj1159.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月16日 星期二 10时44分29秒
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
#define N 5005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

short dp[2][N];
char str1[N],str2[N];
int n,i,j;
short mx;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		CLR(dp,0);
		getchar();
		for(i=1,j=n;i<=n;i++,j--)
		{
			char ch;
			scanf("%c",&ch);
			str1[i]=str2[j]=ch;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(str1[i]==str2[j])
					dp[i%2][j]=dp[(i-1)%2][j-1]+1;
				else
					dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
				mx=max(mx,dp[i%2][j]);
			}
		printf("%d\n",n-mx);
	}

	return 0;
}


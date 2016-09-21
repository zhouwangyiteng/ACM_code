/*************************************************************************
	> File Name: cvs1425.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月21日 星期三 18时23分12秒
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
#define N 21
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,mi,mj;
char str[N][M];
int len[N];
int dp[M][M];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str[i]);
		len[i]=strlen(str[i]);
	}
	int ans=0;
	for(int k=0;k<n-1;k++)
	{
		CLR(dp,0);
		for(int i=0;i<len[k];i++)
			for(int j=0;j<len[k+1];j++)
			{
				if(str[k][i]==str[k+1][j])
					if(i==0||j==0)
						dp[i][j]=1;
					else
						dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=0;
				if(dp[i][j]>ans)
				{
					mi=i;
					mj=j;
					ans=dp[i][j];
				}
			}
		len[k+1]=ans;
		str[k+1][ans--]='\0';
		while(dp[mi][mj]>0)
		{
			str[k+1][ans--]=str[k][mi];
			mi--;
			mj--;
		}
	}
	cout<<str[n-1]<<endl;

	return 0;
}


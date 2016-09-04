/*************************************************************************
	> File Name: cf706c.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月04日 星期日 13时01分08秒
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
#define INF 0x3f3f3f3f3f3f3f3f
#define N 100005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

string str[N][2];
char ch[100000];
int f[N][2];
LL dp[N][2];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		f[i][0]=0;
		scanf("%d",&f[i][1]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch);
		str[i][0]=ch;
		reverse(ch,ch+strlen(ch));
		str[i][1]=ch;
	}
	CLR(dp,0x3f);
	dp[1][0]=0;
	dp[1][1]=f[1][1];
	for(int i=2;i<=n;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				if(str[i-1][j]<=str[i][k])
					dp[i][k]=min(dp[i][k],dp[i-1][j]+f[i][k]);
	if(dp[n][0]==INF&&dp[n][1]==INF)
		cout<<-1<<endl;
	else
		cout<<min(dp[n][0],dp[n][1])<<endl;

	return 0;
}


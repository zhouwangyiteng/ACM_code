/*************************************************************************
	> File Name: poj1080.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月17日 星期三 19时42分37秒
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
#define N 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

char g1[N],g2[N];
int dp[N][N];
int l1,l2;

int match[N][N];

void init()
{
	match['A']['A']=5;match['A']['C']=-1;match['A']['G']=-2;match['A']['T']=-1;match['A']['-']=-3;
	match['C']['A']=-1;match['C']['C']=5;match['C']['G']=-3;match['C']['T']=-2;match['C']['-']=-4;
	match['G']['A']=-2;match['G']['C']=-3;match['G']['G']=5;match['G']['T']=-2;match['G']['-']=-2;
	match['T']['A']=-1;match['T']['C']=-2;match['T']['G']=-2;match['T']['T']=5;match['T']['-']=-1;
	match['-']['A']=-3;match['-']['C']=-4;match['-']['G']=-2;match['-']['T']=-1;
}

int main()
{
	init();
	int t;
	cin>>t;
	while(t--)
	{
		cin>>l1;
		for(int i=0;i<=l1;i++)
			scanf("%c",g1+i);
		cin>>l2;
		for(int i=0;i<=l2;i++)
			scanf("%c",g2+i);
		CLR(dp,0);
		for(int i=1;i<=l1;i++)
			dp[i][0]=dp[i-1][0]+match[g1[i]]['-'];
		for(int i=1;i<=l2;i++)
			dp[0][i]=dp[0][i-1]+match['-'][g2[i]];
		for(int i=1;i<=l1;i++)
			for(int j=1;j<=l2;j++)
			{
				dp[i][j]=max(dp[i-1][j]+match['-'][g1[i]],dp[i][j-1]+match['-'][g2[j]]);
				dp[i][j]=max(dp[i-1][j-1]+match[g1[i]][g2[j]],dp[i][j]);
			}
		cout<<dp[l1][l2]<<endl;
	}

	return 0;
}


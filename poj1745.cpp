/*************************************************************************
	> File Name: poj1745.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月01日 星期一 15时26分12秒
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
#define N 10005
#define K 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

bool dp[N][K];
int a[N];
int n,k;

int pmod(int n,int k)
{
	n=n%k;
	if(n<0) return n+k;
	return n;
}

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	CLR(dp,0);
	dp[1][pmod(a[1],k)]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<k;j++)
			if(dp[i-1][j])
			{
				dp[i][pmod(j+a[i],k)]=1;
				dp[i][pmod(j-a[i],k)]=1;
			}
	if(dp[n][0])
		cout<<"Divisible"<<endl;
	else
		cout<<"Not divisible"<<endl;

	return 0;
}


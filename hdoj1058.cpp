/*************************************************************************
	> File Name: hdoj1058.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月07日 星期日 16时04分52秒
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
#define N 5845
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dp[N];
int n;
int t1,t2,t3,t4;

int main()
{
	dp[0]=1;
	t1=t2=t3=t4=0;
	for(int i=1;i<=N;i++)
	{
		while(dp[t1]*2<=dp[i-1]) t1++;
		while(dp[t2]*3<=dp[i-1]) t2++;
		while(dp[t3]*5<=dp[i-1]) t3++;
		while(dp[t4]*7<=dp[i-1]) t4++;
		int tmp=dp[t1]*2;
		tmp=min(tmp,dp[t2]*3);
		tmp=min(tmp,dp[t3]*5);
		tmp=min(tmp,dp[t4]*7);
		dp[i]=tmp;
	}
	while(cin>>n,n)
	{
		printf("The %d",n);
		if(n%10==1&&n%100!=11)
			cout<<"st";
		else if(n%10==2&&n%100!=12)
			cout<<"nd";
		else if(n%10==3&&n%100!=13)
			cout<<"rd";
		else
			cout<<"th";
		printf(" humble number is %d.\n",dp[n-1]);
	}

	return 0;
}


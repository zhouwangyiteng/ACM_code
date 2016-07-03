#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 105

int a[MAXN][MAXN],dp[MAXN][MAXN];
int c,n;

int main()
{
	cin>>c;
	while(c--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)
			dp[n][i]=a[n][i];
		for(int i=n-1;i>=1;i--)
			for(int j=i;j>=1;j--)
				dp[i][j]=a[i][j]+((dp[i+1][j]>dp[i+1][j+1])?dp[i+1][j]:dp[i+1][j+1]);
		cout<<dp[1][1]<<endl;
	}    
    
	return 0;  
}    

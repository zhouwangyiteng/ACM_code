#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))  
#define MAXN 1000
int dp[MAXN][MAXN]; 
char s1[MAXN],s2[MAXN];

int main()
{
	while(scanf("%s %s",s1,s2)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		int l1=strlen(s1);
		int l2=strlen(s2);
		for(int i=1;i<=l1;i++)
			for(int j=1;j<=l2;j++)
				if(s1[i-1]==s2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		cout<<dp[l1][l2]<<endl;
		
	}
	
	return 0;  
}    

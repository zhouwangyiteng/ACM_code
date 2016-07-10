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

double dp[2][MAXN];
int c,n,m;

int main()
{
	while(scanf("%d",&c)&&c)
	{
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof(dp));
		if(m > n || m > c || (m + n) % 2)
		{  
            printf("0.000\n");  
            continue;  
        } 
		if(n>1000)
			n=1000+n%2;
		dp[0][0]=1.0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=i&&j<=c;j++)
			{
				dp[i%2][j]=0.0;
				if((i+j)&1) continue;
				if(j>0)
					dp[i%2][j]+=dp[1-i%2][j-1]*((c-j+1.0)*1.0/c);
				if(j<=i-2)
					dp[i%2][j]+=dp[1-i%2][j+1]*((j+1.0)*1.0/c);
			}
		printf("%.3lf\n", dp[n%2][m]);
	}

	return 0;  
}    

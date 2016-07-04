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
#define MAXN 65536
#define SIZE 11111
double dp[SIZE];
double Min(double x,double y)
{
    return x<y?x:y;
}
int main()
{
    int i,j;
    int n,m,a[SIZE];
    double b[SIZE];
    while(cin>>n>>m,n+m)
    {
        for(i=0;i<m;i++)
            scanf("%d%lf",&a[i],&b[i]);
        fill(dp,dp+11111,1);
        for(i=0;i<m;i++)
        {
            for(j=n;j>=a[i];j--)
            {
                dp[j]=Min(dp[j],dp[j-a[i]]*(1-b[i]));
            }
        }
        printf("%.1lf%%\n",(1-dp[n])*100);    
    }
    return 0;
}

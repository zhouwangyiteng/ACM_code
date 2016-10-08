/*************************************************************************
	> File Name: cvs3546.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月08日 星期六 17时17分39秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n;
int p[N]; 
LL dp[N][N];
int s[N][N];

void Traceback(int i,int j,int s[][N])
{
	if(i==j)
	{
		cout<<"A"<<i;
		return;
	}
	if(i!=1||j!=n)
		cout<<"(";
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	if(i!=1||j!=n)
		cout<<")";
}

int main()
{
	int icase=0;
	while(cin>>n)
	{
		printf("Case %d\n",++icase);
		for(int i=0;i<=n;i++)
			scanf("%d",p+i);
		for(int i=1;i<=n;i++)
			dp[i][i]=0;
		for(int r=2;r<=n;r++)
			for(int i=1;i<=n-r+1;i++)
			{
				int j=i+r-1;
				dp[i][j]=dp[i+1][j]+p[i-1]*p[i]*p[j];
				s[i][j]=i;
				for(int k=i+1;k<j;k++)
				{
					int t=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
					if(t<dp[i][j])
					{
						dp[i][j]=t;
						s[i][j]=k;
					}
				}
			}
		cout<<dp[1][n]<<' ';
		Traceback(1,n,s);
		cout<<endl;
	}
	
	return 0;
}


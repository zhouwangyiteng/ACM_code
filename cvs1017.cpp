/*************************************************************************
	> File Name: cvs1017.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月06日 星期二 21时05分01秒
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
#define N 45
#define M 10
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

LL dp[N][M];
int a[N];
char str[N];
int n,m;

LL num(int i,int j)
{
	LL res=0;
	for(int k=i;k<=j;k++)
	{
		res*=10;
		res+=a[k];
	}
	return res;
}

int main()
{
	scanf("%d %d",&n,&m);
	scanf("%s",str);
	for(int i=0;i<n;i++)
		a[i]=str[i]-'0';
	CLR(dp,0);
	for(int j=0;j<n;j++)  
        dp[j][0]=num(0,j);  
    for(int j=0;j<n;j++)  
    {  
        for(int k=1;k<=m;k++)  
        {  
            for(int t=0;t<j;t++)  
            {  
                dp[j][k]=max(dp[t][k-1]*num(t+1,j),dp[j][k]);  
            }  
        }  
    }  
    cout<<dp[n-1][m]<<endl;

	return 0;
}


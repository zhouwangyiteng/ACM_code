/*************************************************************************
	> File Name: cvs1068.cpp
	> Author:
	> Mail:
	> Blog:
	> Created Time: 2016年09月23日 星期五 13时11分43秒
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
#define N 355
#define M 40
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N],b[5];
int n,m;
int dp[M][M][M][M];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[0]);
        b[b[0]]++;
    }
    for(int i=1;i<=b[1]+1;i++)
        for(int j=1;j<=b[2]+1;j++)
            for(int k=1;k<=b[3]+1;k++)
                for(int l=1;l<=b[4]+1;l++)
                    dp[i][j][k][l]=max(dp[i-1][j][k][l],max(dp[i][j-1][k][l],max(dp[i][j][k-1][l],dp[i][j][k][l-1])))+a[i+2*(j-1)+3*(k-1)+4*(l-1)];
    cout<<dp[b[1]+1][b[2]+1][b[3]+1][b[4]+1]<<endl;

	return 0;
}


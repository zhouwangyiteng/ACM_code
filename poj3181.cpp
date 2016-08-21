/*************************************************************************
	> File Name: poj3181.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月21日 星期日 11时49分01秒
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
#define N 1005
#define M 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,k;
LL inf=1;
LL a[N][M],b[N][M];

int main()
{
	for(int i=0;i<18;i++)
		inf*=10;
	scanf("%d %d",&n,&k);
	CLR(a,0);
	CLR(b,0);
	for(int i=0;i<=k;i++)
		a[0][i]=1;
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n;i++)
		{
			if(i<j)
			{
				a[i][j]=a[i][j-1];
				b[i][j]=b[i][j-1];
				continue;
			}
			b[i][j]=b[i-j][j]+b[i][j-1]+(a[i-j][j]+a[i][j-1])/inf;
			a[i][j]=(a[i-j][j]+a[i][j-1])%inf;
		}
	if(b[n][k])
		cout<<b[n][k];
	cout<<a[n][k]<<endl;

	return 0;
}


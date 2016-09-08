/*************************************************************************
	> File Name: cvs1085.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月07日 星期三 21时33分48秒
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
#define M 10
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,m;
int dpmax[N][N][M],dpmin[N][N][M],a[N];
int num[N][N];

int f(int i,int j)
{
	int res=0;
	for(int k=i;k<=j;k++)
		res+=a[k];
	res%=10;
	return num[i][j]=(res+10)%10;
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i+n]=a[i];
	}
	n*=2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
			{
				dpmax[i][j][k]=-200;
				dpmin[i][j][k]=200;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dpmax[i][j][1]=dpmin[i][j][1]=f(i,j);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=2;k<=m;k++)
				for(int t=i;t<j;t++)
				{
					dpmax[i][j][k]=max(dpmax[i][j][k],dpmax[i][t][k-1]*num[t+1][j]);
					dpmin[i][j][k]=min(dpmin[i][j][k],dpmin[i][t][k-1]*num[t+1][j]);
				}
	int maxans=-1;
	int minans=INF;
	n/=2;
	for(int i=1;i<=n;i++)
	{
		maxans=max(maxans,dpmax[i][i+n-1][m]);
		minans=min(minans,dpmin[i][i+n-1][m]);
	}
	cout<<minans<<endl;
	cout<<maxans<<endl;

	return 0;
}


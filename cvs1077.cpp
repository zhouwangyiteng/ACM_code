/*************************************************************************
	> File Name: cvs1077.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月02日 星期日 20时53分03秒
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

int m[N][N];
int n,q,a,b;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&m[i][j]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&i!=k)
					if(m[i][k]+m[k][j]<m[i][j])
						m[i][j]=m[i][k]+m[k][j];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",m[a][b]);
	}


	return 0;
}


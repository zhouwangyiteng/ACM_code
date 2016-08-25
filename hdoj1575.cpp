/*************************************************************************
	> File Name: hdoj1575.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月25日 星期四 11时07分11秒
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
#define N 15
#define M 9973
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

struct Mat 
{
    int mat[N][N];
};

int t,n,k;
Mat m;

Mat operator * (Mat a, Mat b) 
{
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for(k = 0; k < n; ++k) 
        for(i = 0; i < n; ++i) 
        	for(j = 0; j < n; ++j) 
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j])%M;
    return c;
}

Mat operator ^ (Mat a, int k) 
{
    Mat c;
    int i, j;
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            c.mat[i][j] = (i == j);

    for(; k; k >>= 1) 
    {
        if(k&1) c = c*a;
        a = a*a;
    }
    return c;
}


int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>m.mat[i][j];
		m=m^k;
		int ans=0;
		for(int i=0;i<n;i++)
			ans+=m.mat[i][i];
		cout<<ans%M<<endl;
	}

	return 0;
}


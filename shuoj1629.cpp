/*************************************************************************
	> File Name: shuoj1629.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月23日 星期六 15时11分48秒
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
#define ll long long
#define INF 0x3f3f3f
#define MAXN 1000000007
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct Mat
{
	ll mat[5][5];

};
Mat operator *(Mat a,Mat b)
{
	Mat c;
	memset(c.mat,0,sizeof(c.mat));
	int i,j,k;
	for(k=0;k<5;k++)
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				c.mat[i][j]=(c.mat[i][j]%MAXN+((a.mat[i][k]%MAXN)*(b.mat[k][j]%MAXN))%MAXN)%MAXN;
	return c;
}

Mat operator ^(Mat a,ll k)
{
	Mat c;
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			c.mat[i][j]=(i==j);
	while(k)
	{
		if(k&1)
			c=c*a;
		a=a*a;
		k>>=1;
	}
	return c;
}

ll n,a0,ax,ay,b0,bx,by;
Mat A,B;

int main()
{
	while(cin>>n>>a0>>ax>>ay>>b0>>bx>>by)
	{
		memset(B.mat,0,sizeof(B.mat));
		B.mat[0][0]=(ax%MAXN*(bx%MAXN))%MAXN;
		B.mat[0][4]=1;
		B.mat[1][0]=(ax%MAXN*(by%MAXN))%MAXN;
		B.mat[1][1]=ax%MAXN;
		B.mat[2][0]=(ay%MAXN*(bx%MAXN))%MAXN;
		B.mat[2][2]=bx%MAXN;
		B.mat[3][0]=(ay%MAXN*(by%MAXN))%MAXN;
		B.mat[3][1]=ay%MAXN;
		B.mat[3][2]=by%MAXN;
		B.mat[3][3]=1;
		B.mat[4][4]=1;
		memset(A.mat,0,sizeof(A.mat));
		A.mat[0][0]=(a0%MAXN*(b0%MAXN))%MAXN; A.mat[0][1]=a0%MAXN; A.mat[0][2]=b0%MAXN; A.mat[0][3]=1; A.mat[0][4]=0;
		Mat t=(A*(B^n));
		cout<<(t.mat[0][4]%MAXN+t.mat[0][0]%MAXN+MAXN-((a0%MAXN)*(b0%MAXN))%MAXN)%MAXN<<endl;
	}

	return 0;
}


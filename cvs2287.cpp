/*************************************************************************
	> File Name: cvs2287.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月12日 星期一 21时30分24秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a,n,m,x;
LL y;
struct node
{
	int aa,yy;
}f[N],up[N],down[N];

int main()
{
	scanf("%d%d%d%d",&a,&n,&m,&x);
	if(x<=2)
		cout<<a<<endl;
	else if(x==3)
		cout<<(2*a)<<endl;
	else if(x==n)
		cout<<0<<endl;
	else
	{
		CLR(f,0);
		CLR(up,0);
		CLR(down,0);
		f[1].aa=1;f[1].yy=0;
		f[2].aa=1;f[2].yy=0;
		f[3].aa=2;f[3].yy=0;
		up[1].aa=1;up[1].yy=0;
		up[2].aa=0;up[2].yy=1;
		up[3].aa=1;up[3].yy=1;
		down[1].aa=0;down[1].yy=0;
		down[2].aa=0;down[2].yy=1;
		down[3].aa=0;down[3].yy=1;
		for(int i=4;i<n;i++)
		{
			up[i].aa=up[i-1].aa+up[i-2].aa;
			up[i].yy=up[i-1].yy+up[i-2].yy;
			down[i].aa=up[i-1].aa;
			down[i].yy=up[i-1].yy;
			f[i].aa=f[i-1].aa+up[i].aa-down[i].aa;
			f[i].yy=f[i-1].yy+up[i].yy-down[i].yy;
		}
		if((m-f[n-1].aa*a<0)||((m-f[n-1].aa*a)%f[n-1].yy!=0))
		{
			cout<<"No answer."<<endl;
			return 0;
		}
		y=(m-f[n-1].aa*a)/f[n-1].yy;
		cout<<(a*f[x].aa+y*f[x].yy)<<endl;
	}


	return 0;
}


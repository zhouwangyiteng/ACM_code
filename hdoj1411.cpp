/*************************************************************************
	> File Name: hdoj1411.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月05日 星期五 14时15分49秒
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
#define INF 0x3f3f3f3f
#define N 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

double a,b,c,l,m,n;

double f()
{
	double ans;
	ans=sqrt((4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n)-c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)+(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n)))/12.0;
	return ans;
}


int main()
{
	while(cin>>a>>c>>b>>n>>l>>m)
	{
		printf("%.4lf\n",f());
	}

	return 0;
}


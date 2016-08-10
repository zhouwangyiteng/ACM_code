/*************************************************************************
	> File Name: hdoj[1]705.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: [2]0[1]6年08月[1]0日 星期三 [2]0时[3]0分45秒
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
#define N 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int x[4],y[4];

int area()
{
	return abs((x[3]-x[1])*(y[2]-y[1])-(x[2]-x[1])*(y[3]-y[1]))/2;
}

int gcd(int x,int y)
{
	if(!x||!y) return x>y?x:y;
	for(int t;t=x%y;x=y,y=t);
	return y;
}

int main()
{
	while(scanf("%d %d %d %d %d %d",&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]),x[1]||x[2]||x[3]||y[1]||y[2]||y[3])
	{
		int S=area();
		int s=gcd(abs(x[1]-x[2]),abs(y[1]-y[2]))+gcd(abs(x[1]-x[3]),abs(y[1]-y[3]))+gcd(abs(x[2]-x[3]),abs(y[2]-y[3]));
		cout<<(S+1-s/2)<<endl;
	}

	return 0;
}


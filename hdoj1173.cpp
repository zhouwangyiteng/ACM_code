/*************************************************************************
	> File Name: hdoj1173.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月25日 星期一 20时22分15秒
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
#define N 1000000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

double x[N],y[N];
int n;

int main()
{
	while(cin>>n,n)
	{
		for(int i=0;i<n;i++)
			scanf("%lf%lf",x+i,y+i);
		sort(x,x+n);
		sort(y,y+n);
		if(n&1)
			printf("%.2lf %.2lf\n",x[n/2],y[n/2]);
		else
			printf("%.2lf %.2lf\n",(x[n/2-1]+x[n/2])/2,(y[n/2-1]+y[n/2])/2);
	}

	return 0;
}


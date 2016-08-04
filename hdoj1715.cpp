/*************************************************************************
	> File Name: hdoj1715.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月04日 星期四 21时47分23秒
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
#define N 1010
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int f[N][300];
int n;

void Plus(int a[],int b[],int c[])
{
	int lb,lc;
	lb=b[0];
	lc=c[0];
	int la=max(lb,lc);
	for(int i=1;i<=la;i++)
	{
		a[i]+=(b[i]+c[i]);
		a[i+1]=a[i]/10;
		a[i]%=10;
	}
	if(a[la+1]>0)
		la++;
	a[0]=la;
}

int main()
{
	CLR(f,0);
	f[1][0]=f[1][1]=f[2][1]=f[2][0]=1;
	for(int i=3;i<N;i++)
		Plus(f[i],f[i-1],f[i-2]);
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		int l=f[n][0];
		for(int i=l;i>0;i--)
			printf("%d",f[n][i]);
		cout<<endl;
	}


	return 0;
}


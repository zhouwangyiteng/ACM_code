/*************************************************************************
	> File Name: poj2229.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月25日 星期一 15时49分58秒
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
#define N 1000005
#define MAXN 1000000000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int n;

int main()
{
	cin>>n;
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=n;i++)
		if(i&1)
			a[i]=a[i-1];
		else
			a[i]=(a[i-1]+a[i/2]) % MAXN;
	cout<<a[n]<<endl;

	return 0;
}


/*************************************************************************
	> File Name: poj1503.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月28日 星期四 21时49分11秒
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
#define N 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

short a[N],b[N];
char str[N];
int la,lb;

void Plus(short a[],short b[])
{
	if(la==0)
	{
		la=lb;
		for(int i=0;i<la;i++)
			a[i]=b[i];
	}
	else
	{
		int n=max(la,lb);
		for(int i=0;i<n;i++)
		{
			a[i]+=b[i];
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
		if(a[n]>0)
			la=n+1;
		else
			la=n;
	}
}

int main()
{
	CLR(a,0);
	la=lb=0;
	while(scanf("%s",str))
	{
		lb=strlen(str);
		if(str[0]=='0'&&lb==1)
			break;
		CLR(b,0);
		for(int i=lb-1;i>=0;i--)
			b[lb-i-1]=(int)(str[i]-'0');
		Plus(a,b);
	}
	for(int i=la-1;i>=0;i--)
		cout<<a[i];
	cout<<endl;

	return 0;
}


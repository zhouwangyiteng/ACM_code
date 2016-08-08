/*************************************************************************
	> File Name: hdoj1452.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月08日 星期一 09时46分25秒
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

int x;

int POW(int a,int n)
{
	int res=1;
	while(n)
	{
		if(n&1)
			res=(res*a)%29;
		a=(a*a)%29;
		n>>=1;
	}
	return (res+28)%29;
}

int main()
{
	while(cin>>x,x)
	{
		int ans=POW(2,2*x+1)%29;
		ans*=POW(3,x+1)%29;
		ans*=POW(22,x+1)*9%29;
		cout<<ans%29<<endl;
	}

	return 0;
}


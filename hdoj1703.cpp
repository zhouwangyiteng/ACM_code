/*************************************************************************
	> File Name: hdoj1703.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月10日 星期三 14时40分56秒
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

int n;

int main()
{
	while(cin>>n,n)
	{
		if(n==1)
			cout<<0;
		else if(n==2)
			cout<<5;
		else if(n==3)
			cout<<15;
		else if(n>=4)
			cout<<(5*(2*n-4));
		cout<<endl;
	}

	return 0;
}


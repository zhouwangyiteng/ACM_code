/*************************************************************************
	> File Name: poj1067.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月17日 星期三 15时13分12秒
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

int a,b,i;

int main()
{
	while(cin>>a>>b)
	{
		if(a<b)
		{
			a^=b;
			b^=a;
			a^=b;
		}
		int i=a-b;
		a=(int)(i*(1+sqrt(5))/2.0);
		if(a==b)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}

	return 0;
}


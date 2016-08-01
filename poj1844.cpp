/*************************************************************************
	> File Name: poj1844.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月01日 星期一 11时29分43秒
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

int s,i,sum;

int main()
{
	while(scanf("%d",&s)!=EOF)
	{
		sum=i=0;
		while(sum<s||(sum-s)&1)
			sum+=++i;
		cout<<i<<endl;
	}

	return 0;
}


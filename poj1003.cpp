/*************************************************************************
	> File Name: poj1003.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月17日 星期三 16时53分13秒
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
double g,cur;

int main()
{
	while(cin>>g)
	{
		if(g==0)
			break;
		cur=0;
		n=0;
		while(cur<g)
		{
			n++;
			cur+=1.0/(n+1);
		}
		cout<<n<<" card(s)"<<endl;
	}

	return 0;
}


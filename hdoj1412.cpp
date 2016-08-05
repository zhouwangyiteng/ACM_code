/*************************************************************************
	> File Name: hdoj1412.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月05日 星期五 14时25分01秒
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

set<int> s;
int n,m;

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		n+=m;
		s.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			s.insert(m);
		}
		std::set<int>::iterator it=s.begin();
		cout<<*it;
		it++;
		for(;it!=s.end();it++)
			printf(" %d",*it);
		cout<<endl;

	}

	return 0;
}


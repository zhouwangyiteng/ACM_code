/*************************************************************************
	> File Name: hdoj1004.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月10日 星期三 16时40分48秒
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

string str;
map<string,int> mp;
int n;

int main()
{
	while(cin>>n,n)
	{
		mp.clear();
		for(int i=0;i<n;i++)
		{
			cin>>str;
			mp[str]++;
		}
		int MAX=0;
		for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
			if(it->Y>MAX)
			{
				str=it->X;
				MAX=it->Y;
			}
		cout<<str<<endl;
	}

	return 0;
}


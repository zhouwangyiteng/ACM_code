/*************************************************************************
	> File Name: hdoj1053.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月09日 星期二 16时08分01秒
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
priority_queue<int,vector<int>,greater<int> > que;
map<char,int> mp;

int main()
{
	while(cin>>str,str.compare("END")!=0)
	{
		int len=str.size();
		mp.clear();
		while(!que.empty())
			que.pop();
		for(int i=0;i<len;i++)
			mp[str[i]]++;
		for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
			que.push(it->second);
		int sum=0;
		if(que.size()==1)
			sum=que.top();
		while(que.size()>1)
		{
			int a=que.top();
			que.pop();
			int b=que.top();
			que.pop();
			sum+=a+b;
			que.push(a+b);
		}
		printf("%d %d %.1f\n",8*len,sum,8.0*len/sum);
	}

	return 0;
}


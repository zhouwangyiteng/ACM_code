/*************************************************************************
	> File Name: ICPC2016dalian/1009.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月10日 星期六 14时28分21秒
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
#define N 200100
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int x,step;
	node(){};
	node(int a,int b):x(a),step(b){};
};
queue<node> que;
vector<int> vec;
map<pair<int,int>,int> mp;
set<int> st;
int n,m,s,t;
int a[N];

void init()
{
	mp.clear();
	CLR(a,-1);
	st.clear();
	for(int i=1;i<=n;i++)
		st.insert(i);
}

void bfs()
{
	st.erase(s);
	que.push(node(s,0));
	while(!que.empty())
	{
		node q=que.front();
		que.pop();
		vec.clear();
		for(set<int>::iterator it=st.begin();it!=st.end(); ++it)
		{
			int p=*it;
			if(mp[MP(p,q.x)]==0)
			{
				a[p]=q.step+1;
				que.push(node(p,q.step+1));
				vec.push_back(p);
			}
		}
		for(int i=0;i<vec.size();i++)
			st.erase(vec[i]);		
	}
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		init();
		for(int i=1;i<=m;i++)
		{
			int x,y1;
			scanf("%d %d",&x,&y1);
			mp[MP(x,y1)]=1;
			mp[MP(y1,x)]=1;
		}
		scanf("%d",&s);
		bfs();
		bool fir=true;
		for(int i=1;i<=n;i++)
			if(i!=s)
			{
				if(fir)
				{
					printf("%d",a[i]);
					fir=false;
				}
				else
					printf(" %d",a[i]);
			}
		printf("\n");
	}

	return 0;
}


/*************************************************************************
	> File Name: cvs1225.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月21日 星期三 19时16分08秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int g[4][4],x,y,step;
	string str;
};
queue<node> que;
node a,b;
int gz[4][4],ans;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
map<string,int> mp;

bool yes()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(a.g[i][j]!=gz[i][j])
				return false;
	return true;
}

void bfs()
{
	while(!que.empty())
	{
		a=que.front();
		if(yes())
		{
			ans=a.step;
			return;
		}
		que.pop();
		for(int i=0;i<4;i++)
		{
			int tx=a.x+dir[i][0];
			int ty=a.y+dir[i][1];
			if(tx>=0&&tx<3&&ty>=0&&ty<3)
			{
				b.x=tx;
				b.y=ty;
				b.step=a.step+1;
				for(int k=0;k<3;k++)
					for(int j=0;j<3;j++)
						b.g[k][j]=a.g[k][j];
				b.g[tx][ty]=a.g[a.x][a.y];
				b.g[a.x][a.y]=a.g[tx][ty];
				b.str=a.str;
				for(int k=0;k<3;k++)
					for(int j=0;j<3;j++)
						b.str[3*k+j]=(char)('0'+b.g[k][j]);
				if(!mp[b.str])
				{
					mp[b.str]=1;
					que.push(b);
				}
			}
		}
	}
}

int main()
{
	cin>>a.str;
	mp[a.str]=1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			a.g[i][j]=(int)(a.str[3*i+j]-'0');
			if(a.g[i][j]==0)
			{
				a.x=i;
				a.y=j;
			}
		}
	gz[0][0]=1;gz[0][1]=2;gz[0][2]=3;
	gz[1][0]=8;gz[1][1]=0;gz[1][2]=4;
	gz[2][0]=7;gz[2][1]=6;gz[2][2]=5;
	que.push(a);
	bfs();
	cout<<ans<<endl;

	return 0;
}


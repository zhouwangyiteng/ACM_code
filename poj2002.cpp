/*************************************************************************
	> File Name: poj2002.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月30日 星期六 11时04分46秒
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
#define N 1005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int x,y;
	int next;
}p[N];
int hash[2*N];
int n,ans,tx,ty;

bool find(int xx,int yy)
{
	int h=(xx*xx+yy*yy)%(2*N);
	for(int i=hash[h];i!=-1;i=p[i].next)
		if(p[i].x==xx&&p[i].y==yy)
			return true;
	return false;
}

int main()
{
	while(cin>>n,n)
	{
		CLR(hash,-1);
		CLR(p,0);
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&tx,&ty);
			int h=(tx*tx+ty*ty)%(2*N);
			p[i].x=tx;
			p[i].y=ty;
			p[i].next=hash[h];
			hash[h]=i;
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				int a=p[j].x-p[i].x;
				int b=p[j].y-p[i].y;

				int x3=p[i].x+b;
				int y3=p[i].y-a;
				int x4=p[j].x+b;
				int y4=p[j].y-a;
				
				if(find(x3,y3) && find(x4,y4))
					ans++;

				x3=p[i].x-b;
				y3=p[i].y+a;
				x4=p[j].x-b;
				y4=p[j].y+a;

				if(find(x3,y3) && find(x4,y4))
					ans++;
			}
		cout<<ans/4<<endl;
	}

	return 0;
}


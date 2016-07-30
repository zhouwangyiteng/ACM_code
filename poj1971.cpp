/*************************************************************************
	> File Name: poj1971.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月29日 星期五 20时47分31秒
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
	int x,y,cnt,next;
}p[N*N];
int hash[1000000];
int t,n,ans,tx,ty;
int x[N],y[N];


int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		CLR(hash,-1);
		CLR(p,0);
		int top=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&tx,&ty);
			for(int j=0;j<i;j++)
			{
				int flag=true;
				int xx=tx+x[j];
				int yy=ty+y[j];
				int h=abs(xx+yy)%1000000;
				for(int k=hash[h];k!=-1;k=p[k].next)
					if(p[k].x==xx&&p[k].y==yy)
					{
						p[k].cnt++;
						ans+=p[k].cnt;
						flag=false;
						break;
					}
				if(flag)
				{
					p[top].x=xx;
					p[top].y=yy;
					p[top].next=hash[h];
					hash[h]=top++;
				}
			}
			x[i]=tx;
			y[i]=ty;
		}
		cout<<ans<<endl;
	}

	return 0;
}


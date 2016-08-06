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
#define INF 0x3f3f3f
#define N 100005
#define M 1000000007
#define MD(X,Y) ((X)%(Y)+(Y))%(Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int box[N];
bool vis[N];
int cnt;
int n,m;

bool yes(int t)
{
	return ((1<<m)-1)==t;
}

void dfs(int i,int t)
{
	t|=box[i];
	if(yes(t))
	{
		cnt+=(int)(pow(2.0,n-1-i))%M;
		cnt%=M;
		return;
	}
	for(int j=i+1;j<n;j++)
		if(!vis[j])
		{
			vis[j]=1;
			dfs(j,t);
			vis[j]=0;
		}
}


int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		CLR(box,0);
		for(int i=0;i<n;i++)
		{
			int t;
			scanf("%d",&t);
			for(int j=0;j<t;j++)
			{
				int dt;
				scanf("%d",&dt);
				box[i]+=1<<(dt-1);
			}
		}
		CLR(vis,0);
		cnt=0;
		for(int i=0;i<n;i++)
		{
			vis[i]=1;
			dfs(i,0);
			vis[i]=0;
		}
		cout<<cnt<<endl;
	}

	return 0;
}


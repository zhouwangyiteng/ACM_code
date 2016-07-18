#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 100005

struct node
{
	int a,c;
	node(int x=0,int y=0):a(x),c(y){}
};
queue<node> que;
short vis[MAXN];
int n,k,ans;

int bfs()
{
	if(n==k)
		return 0;
	while(!que.empty())
	{
		node p=que.front();
		que.pop();
		long long tmp=p.a-1;
		if(tmp==k)
			return p.c+1;
		if(tmp>=0&&tmp<=MAXN&&!vis[tmp])
		{
			vis[tmp]=1;
			que.push(node(tmp,p.c+1));
		}
		tmp=p.a+1;
		if(tmp==k)
			return p.c+1;
		if(tmp>=0&&tmp<=MAXN&&!vis[tmp])
		{
			vis[tmp]=1;
			que.push(node(tmp,p.c+1));
		}
		tmp=p.a*2;
		if(tmp==k)
			return p.c+1;
		if(tmp>=0&&tmp<=MAXN&&!vis[tmp])
		{
			vis[tmp]=1;
			que.push(node(tmp,p.c+1));
		}
	}
}

int main()
{
    while(cin>>n>>k)
    {
		memset(vis,0,sizeof(vis));
   		while(!que.empty())
    		que.pop();
    	que.push(node(n,0));
    	vis[n]=1;
    	ans=bfs();
    	cout<<ans<<endl;
    }
    
	return 0;  
}    

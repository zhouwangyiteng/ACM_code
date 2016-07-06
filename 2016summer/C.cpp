#include<vector>
#include<cmath>
#include<algorithm>
#include <map>
#include <iostream>

using namespace std;
#define MAXN 10005
#define INF 0x3f3f3f3f
int vis[MAXN];
int n,m,num,sum;
bool flag;

void dfs(int num,int sum)
{
	if(flag)
		return;
	if(num==2)
	{
		if((m-sum)<=n&&!vis[m-sum])
			flag=1;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(num+1,sum+i);
			vis[i]=0;
			if(flag)
				return;
		}
	}
}

int main()
{	
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		if(m>3*n-3)
		{
			cout<<"No"<<endl;
			continue;
		}
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(flag)
				for(int j=1;j<=n;j++)
				{
					int t=m-i-j;
					if(i!=j&&i!=t&&t!=j&&t<=n&&t>0)
					{
						cout<<"Yes"<<endl;
						flag=0;
						break;
					}
				}
		}
		if(flag)
			cout<<"No"<<endl;
		/*
fill(vis,vis+MAXN,0);
		flag=0;
		dfs(0,0);
		if(flag)
			cout<<"Yes"<<endl;
		else	
			cout<<"No"<<endl;*/
	}
	

	return 0;
}
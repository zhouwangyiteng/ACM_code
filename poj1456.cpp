#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 10005

int n;
long long ans;
struct node
{
	int p;
	int t;
};
node pro[MAXN];
bool vis[MAXN];

int cmp(const void *a,const void *b)
{
	struct node *c=(node *)a;
	struct node *d=(node *)b;
	if(c->p!=d->p)
		return d->p - c->p;
	else
		return d->t - c->t;
}

int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>pro[i].p>>pro[i].t;
		memset(vis,false,sizeof(vis));
		qsort(pro+1,n,sizeof(pro[1]),cmp);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[pro[i].t])
			{
				vis[pro[i].t]=true;
				ans+=pro[i].p;
				continue;
			}
			int j;
			for(j=pro[i].t;j>=1;j--)
				if(!vis[pro[i].t])
					break;
			if(j>=1)
			{
				vis[j]=true;
				ans+=pro[i].p;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;  
}    

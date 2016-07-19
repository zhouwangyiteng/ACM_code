#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 1005

int ind[26],outd[26],p[26],vis[26];
int t,n;

int findp(int a)
{
	while(p[a]>=0)
		a=p[a];
	return a;
}

void Union(int a,int b)
{
	int pa=findp(a);
	int pb=findp(b);
	if(pa==pb)
		return;
	p[pb]+=p[pa];
	p[pa]=pb;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(p,-1,sizeof(p));
		memset(ind,0,sizeof(ind));
		memset(outd,0,sizeof(outd));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			char w[MAXN];
			cin>>w;
			int a=(int)(w[0]-'a');
			int b=(int)(w[strlen(w)-1]-'a');
			outd[a]++;
			ind[b]++;
			Union(a,b);
			vis[a]=vis[b]=1;
		}
		int a=0,b=0;
		for(int i=0;i<26;i++)
		{
			if(ind[i]-outd[i]<0)
				a+=outd[i]-ind[i];
			if(ind[i]-outd[i]>0)
				b+=ind[i]-outd[i];
			if(a>1||b>1)
				break;
		}
		int flag=0;
		for(int i=0;i<26;i++)
		{
			if(p[i]<=-1&&vis[i])
				flag++;
		}
		if(flag<=1&&((!a&&!b)||(a==1&&b==1)))
			cout<<"Ordering is possible."<<endl;
		else
			cout<<"The door cannot be opened."<<endl;
	}    
    
	return 0;  
}    

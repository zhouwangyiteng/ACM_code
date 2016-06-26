#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 30001

int set[MAXN];

int Find(int v)
{
	while(set[v]>=0)
	{
		v=set[v];
	}
	return v;
}

void Union(int v, int u)
{
	int vp=Find(v);
	int up=Find(u);
	if(up==vp) return;
	int temp=set[vp]+set[up];
	set[vp]=up;
	set[up]=temp;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		for(int i=0;i<n;i++)
			set[i]=-1;
		while(m--)
		{
			int num;
			cin>>num;
			int t,head;
			cin>>head;
			num--;
			while(num--)
			{
				cin>>t;
				Union(t,head);	
			}
		}
		cout<<-1*set[Find(0)]<<endl;
	}    
    
	return 0;  
}    

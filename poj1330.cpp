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

int p[MAXN];
int t,n,x,y;

int main()
{
	cin>>t;
	while(t--)
	{
		memset(p,-1,sizeof(p));
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			cin>>a>>b;
			p[b]=a;
		}
		cin>>x>>y;
		vector<int> v1,v2;
		while(x!=-1)
		{
			v1.push_back(x);
			x=p[x];
		}
		while(y!=-1)
		{
			v2.push_back(y);
			y=p[y];
		}
		int flag=0;
		int l1=v1.size();
		int l2=v2.size();
		for(int i=0;i<l1;i++)
		{
			if(flag)
				break;
			for(int j=0;j<l2;j++)
				if(v1[i]==v2[j])
				{
					flag=v1[i];
					break;
				}
		}
		cout<<flag<<endl;
	}   
    
	return 0;  
}    

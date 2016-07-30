/*************************************************************************
	> File Name: poj2549.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月30日 星期六 14时13分10秒
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
#define N 1000005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int num,x,y,next;
}sum[N];
int hash[N];
int n,ans,top;
int a[1005];

bool find(int a,int xx,int yy)
{
	int h=abs(a)%N;
	for(int i=hash[h];i!=-1;i=sum[i].next)
		if(sum[i].num==a)
			if(sum[i].x!=xx&&sum[i].x!=yy&&sum[i].y!=xx&&sum[i].y!=yy)
				return true;
	return false;
}


int main()
{
	while(cin>>n,n)
	{
		CLR(hash,-1);
		CLR(sum,0);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int sz = unique(a,a+n)-a; 
		n=sz;
		top=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				int h=abs(a[i]+a[j])%N;
				sum[top].x=i;
				sum[top].y=j;
				sum[top].num=a[i]+a[j];
				sum[top].next=hash[h];
				hash[h]=top++;
			}
		ans=-1;
		int flag=1;
		for(int i=n-1;i>=0&&flag;i--)
			for(int j=i-1;j>=0;j--)
				if(find(a[i]-a[j],i,j))
				{
					ans=a[i];
					flag=0;
					break;
				}
		if(ans!=-1)
			cout<<ans<<endl;
		else
			cout<<"no solution"<<endl;

	}

	return 0;
}


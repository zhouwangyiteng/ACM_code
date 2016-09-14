/*************************************************************************
	> File Name: cvs3286.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月14日 星期三 21时26分01秒
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
#define LL long long
#define INF 0x3f3f3f3f
#define N 100005
#define M 99999997 
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N],b[N],c[N],B[N],t[N];
map<int,int> amp;
map<int,int> bmp;
int n;

int lowbit(int i)
{
	return i&-i;
}

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=B[i];
		i-=lowbit(i);
	}
	return s;
}

void add(int i,int x)
{
	while(i<=n)
	{
		B[i]+=x;
		i+=lowbit(i);
	}
}


int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		t[i]=a[i];
	}
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++)
		amp[t[i]]=i;
	for(int i=1;i<=n;i++)
		a[i]=amp[a[i]];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",b+i);
		t[i]=b[i];
	}
	sort(t+1,t+1+n);
	for(int i=1;i<=n;i++)
		bmp[t[i]]=i;
	for(int i=1;i<=n;i++)
		b[i]=bmp[b[i]];
	for(int i=1;i<=n;i++)
		amp[a[i]]=i;
	for(int i=1;i<=n;i++)
		c[i]=amp[b[i]];
	int ans=0;
	for(int i=n;i>0;i--)
	{
		ans=(ans+sum(c[i]))%M;
		add(c[i],1);
	}
	cout<<ans<<endl;

	return 0;
}


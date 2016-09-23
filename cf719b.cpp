/*************************************************************************
	> File Name: cf719b.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月23日 星期五 21时25分16秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,cnt,ans;
int a[N],b[N],c[N];
char ch;

int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&ch);
		if(ch=='r')
			a[i]=1;
		else
			a[i]=0;
	} 
	int c1,c2;
	c1=0;
	c2=1;
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-c1;
		c[i]=a[i]-c2;
		c1^=1;
		c2^=1;
	}
	c1=c2=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
			c1++;
		if(b[i]==-1)
			c2++;
	}
	ans=max(c1,c2);
	c1=c2=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]==1)
			c1++;
		if(c[i]==-1)
			c2++;
	}
	cnt=max(c1,c2);

	cout<<min(ans,cnt)<<endl;

	return 0;
}


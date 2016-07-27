/*************************************************************************
	> File Name: hdoj1711.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月27日 星期三 17时03分29秒
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
#define N 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int p[10005],num[10005],s[1000005];
int n,m,t;

void Next()
{
	int i=0,j=-1;
	num[0]=-1;
	while(i<m)
	{
		if(j==-1||p[i]==p[j])
			num[++i]=++j;
		else
			j=num[j];
	}
}

int kmp()
{
	int i=0,j=0;
	while(i<n&&j<m)
	{
		if(j==-1||s[i]==p[j])
			++i,++j;
		else
			j=num[j];
		if(j==m)
			return i-m+1;
	}
	return -1;
}

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",s+i);
		for(int i=0;i<m;i++)
			scanf("%d",p+i);
		Next();
		cout<<kmp()<<endl;
	}

	return 0;
}


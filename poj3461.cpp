/*************************************************************************
	> File Name: poj3461.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月27日 星期三 16时37分11秒
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

char p[10005],s[1000005];
int num[10005];
int t,pn,sn;

void Next()
{
	int i=0,j=-1;
	num[0]=-1;
	while(i<pn)
	{
		if(j==-1||p[i]==p[j])
			num[++i]=++j;
		else
			j=num[j];
	}
}

int kmp()
{
	int i=0,j=0,cnt=0;
	while(i<pn&&j<sn)
	{
		if(p[i]==s[j]||i==-1)
			i++,j++;
		else
			i=num[i];
		if(i==pn)
			cnt++,i=num[i];
	}
	return cnt;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>p;
		cin>>s;
		pn=strlen(p);
		sn=strlen(s);
		Next();
		cout<<kmp()<<endl;
	}

	return 0;
}


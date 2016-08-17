/*************************************************************************
	> File Name: poj1007.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月17日 星期三 20时59分40秒
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
#define N 55
#define M 105
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int b[5];
int n,m;
char str[N];
map<char,int> cti;
map<int,char> itc;
struct node
{
	int a[N];
	int lv;
};

node g[M];

bool cmp(node a,node b)
{
	return a.lv<b.lv;
}

int lowbit(int i)
{
	return i&-i;
}

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=b[i];
		i-=lowbit(i);
	}
	return s;
}

void add(int i,int x)
{
	while(i<=n)
	{
		b[i]+=x;
		i+=lowbit(i);
	}
}

void init()
{
	cti['A']=1;
	cti['C']=2;
	cti['G']=3;
	cti['T']=4;
	itc[1]='A';
	itc[2]='C';
	itc[3]='G';
	itc[4]='T';
}

int main()
{
	init();
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		scanf("%s",str);
		string stri=str;
		g[i].lv=0;
		CLR(b,0);
		for(int j=n-1;j>=0;j--)
		{
			int t=cti[stri[j]];
			g[i].a[j]=t;
			g[i].lv+=sum(t-1);
			add(t,1);
		}
	}
	sort(g,g+m,cmp);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			printf("%c",itc[g[i].a[j]]);
		printf("\n");
	}


	return 0;
}


/*************************************************************************
	> File Name: poj3276.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月25日 星期一 09时58分51秒
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
#define N 5005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int dir[N],f[N];
int n;
char ch;

int calc(int k)
{
	CLR(f,0);
	int sum=0;
	int res=0;
	for(int i=0;i+k<=n;i++)
	{
		if((dir[i]+sum)&1)
		{
			res++;
			f[i]=1;
		}
		sum+=f[i];
		if(i-k+1>=0)
			sum-=f[i-k+1];
	}
	for(int i=n-k+1;i<n;i++)
	{
		if((dir[i]+sum)&1)
			return -1;
		if(i-k+1>=0)
			sum-=f[i-k+1];
	}
	return res;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		if(ch=='F')
			dir[i]=0;
		else
			dir[i]=1;
	}
	int K=0,M=n;
	for(int k=1;k<=n;k++)
	{
		int m=calc(k);
		if(m>0&&M>m)
		{
			K=k;
			M=m;
		}
	}
	cout<<K<<' '<<M<<endl;

	return 0;
}


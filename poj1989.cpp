/*************************************************************************
	> File Name: poj1989.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月23日 星期二 16时04分12秒
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
#define M 10005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int vis[M];
int n,m;
int k,ans;

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	ans=k=0;
	CLR(vis,0);
	for(int i=0;i<n;i++)
	{
		if(!vis[a[i]])
		{
			k++;
			vis[a[i]]=1;
		}
		if(k==m)
		{
			ans++;
			k=0;
			CLR(vis,0);
		}
	}
	cout<<ans+1<<endl;

	return 0;
}


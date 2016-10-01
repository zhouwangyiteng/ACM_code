/*************************************************************************
	> File Name: cf363b.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年10月01日 星期六 14时56分41秒
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
#define N 150005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,k,sum,ans;
int a[N];
int cnt[N];

int main()
{
	scanf("%d%d",&n,&k);
	cnt[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		cnt[i]=cnt[i-1]+a[i];
	}
	ans=1;
	sum=cnt[k];
	for(int i=2;i+k-1<=n;i++)
		if(cnt[i+k-1]-cnt[i-1]<sum)
		{
			ans=i;
			sum=cnt[i+k-1]-cnt[i-1];
		}
	cout<<ans<<endl;

	return 0;
}


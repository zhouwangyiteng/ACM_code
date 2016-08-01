/*************************************************************************
	> File Name: hdoj2535.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月01日 星期一 18时43分22秒
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
#define N 101
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int n,ans;

int main()
{
	while(cin>>n,n)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		n/=2;
		ans=0;
		for(int i=0;i<=n;i++)
			ans+=(int)(a[i]/2)+1;
		cout<<ans<<endl;
	}

	return 0;
}


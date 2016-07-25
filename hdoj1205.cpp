/*************************************************************************
	> File Name: hdoj1205.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月25日 星期一 20时48分37秒
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

int n,t,MAX,a;
ll sum;

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		sum=0;MAX=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			sum+=a;
			if(a>MAX)
				MAX=a;
		}
		if(sum-MAX>=MAX-1)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}


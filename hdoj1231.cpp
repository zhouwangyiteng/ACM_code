/*************************************************************************
	> File Name: hdoj1231.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月25日 星期一 19时26分48秒
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
#define N 10005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int n;

int main()
{
	while(cin>>n,n)
	{
		int start=0,end=0,flag=0,cnt=0,sum=-INF,t=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",a+i);
			if(a[i]>=0)
				t=1;
		}
		for(int i=0;i<n;i++)
		{
			cnt+=a[i];
			if(cnt>sum)
			{
				sum=cnt;
				start=a[flag];
				end=a[i];
			}
			if(cnt<0)
			{
				cnt=0;
				flag=i+1;
			}
		}
		if(t)
			cout<<sum<<' '<<start<<' '<<end<<endl;
		else
			cout<<0<<' '<<a[0]<<' '<<a[n-1]<<endl;
	}

	return 0;
}


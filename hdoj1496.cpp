/*************************************************************************
	> File Name: hdoj1496.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月07日 星期日 10时19分04秒
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
#define N 2000005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int x1,x2,x3,x4;
int a,b,c,d;
ll cnt;
int Hash[N];

int main()
{
	while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
	{
		cnt=0;
		if(a>0&&b>0&&c>0&&d>0)
		{
			cout<<0<<endl;
			continue;
		}
		CLR(Hash,0);
		for(x1=-100;x1<=100;x1++)
			for(x2=-100;x2<=100;x2++)
				if(x1!=0&&x2!=0)
				{
					int tmp=a*x1*x1+b*x2*x2;
					if(tmp<0)
						tmp+=N;
					Hash[tmp]++;
				}
		for(x3=-100;x3<=100;x3++)
			for(x4=-100;x4<=100;x4++)
				if(x3!=0&&x4!=0)
				{
					int tmp=-(c*x3*x3+d*x4*x4);
					if(tmp<0)
						tmp+=N;
					cnt+=Hash[tmp];
				}
		printf("%lld\n",cnt);
	}

	return 0;
}


/*************************************************************************
	> File Name: hdoj1407.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月04日 星期四 21时12分31秒
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
#define N 72
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

struct node
{
	int a,b,c;
};
node num[10005];
bool Hash[10005];
int n;

int main()
{
	CLR(Hash,0);
	for(int i=100;i>=1;i--)
		for(int j=100;j>=1;j--)
			for(int k=100;k>=1;k--)
			{
				int h=i*i+j*j+k*k;
				if(h<=10000)
				{
					Hash[h]=1;
					num[h].a=i;
					num[h].b=j;
					num[h].c=k;
				}
			}
	while(scanf("%d",&n)!=EOF)
	{
		if(Hash[n])
			printf("%d %d %d\n",num[n].a,num[n].b,num[n].c);
	}

	return 0;
}


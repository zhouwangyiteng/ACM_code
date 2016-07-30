/*************************************************************************
	> File Name: hdoj1106.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月30日 星期六 18时38分15秒
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
#define N 1005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
char str[N];
int num,top;

int main()
{
	while(scanf("%s",str)!=EOF)
	{
		int len=strlen(str);
		top=0;
		num=0;
		int flag=0;
		for(int i=0;i<len;i++)
		{
			if(str[i]=='5')
			{
				if(flag)
				{
					a[top++]=num/10;
					num=0;
					flag=0;
				}
			}
			else
			{
				num+=(int)(str[i]-'0');
				num*=10;
				flag=1;
			}
		}
		if(flag)
			a[top++]=num/10;
		sort(a,a+top);
		cout<<a[0];
		for(int i=1;i<top;i++)
			printf(" %d",a[i]);
		cout<<endl;
	}

	return 0;
}


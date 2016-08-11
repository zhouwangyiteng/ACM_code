/*************************************************************************
	> File Name: hdoj1279.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月11日 星期四 10时13分43秒
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
#define N 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,d;
queue<int> que;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&d);
		int flag=-1;
		while(d!=1)
		{
			if(d&1)
			{
				que.push(d);
				d=3*d+1;
			}
			else
				d/=2;
		}
		if(que.empty())
			printf("No number can be output !");
		else
		{
			printf("%d",que.front());
			que.pop();
			while(!que.empty())
			{	
				printf(" %d",que.front());
				que.pop();
			}
		}
		cout<<endl;
	}

	return 0;
}


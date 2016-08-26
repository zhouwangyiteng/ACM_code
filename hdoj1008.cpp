/*************************************************************************
	> File Name: hdoj1008.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月26日 星期五 19时37分18秒
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
#define N 105
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N];
int cur,n;
LL cnt;

int main()
{
	while(cin>>n,n)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		cur=cnt=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]>cur)
			{
				cnt+=5+6*(a[i]-cur);
				cur=a[i];
			}
			else if(a[i]<cur)
			{
				cnt+=5+4*(cur-a[i]);
				cur=a[i];
			}
			else
				cnt+=5;
		}
		cout<<cnt<<endl;
	}

	return 0;
}


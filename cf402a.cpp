/*************************************************************************
	> File Name: cf402a.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月11日 星期日 21时32分55秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int k,a,b,v;
int cnt,num;

int main()
{
	while(scanf("%d %d %d %d",&k,&a,&b,&v)!=EOF)
	{
		cnt=0;
		while(1)
		{
			if(a<=0)
				break;
			num=1;
			if(b>0)
			{
				if(b>=k-1)
				{
					num=k;
					b-=k-1;
				}
				else
				{
					num+=b;
					b=0;
				}
			}
			a-=num*v;
			cnt++;
		}
		cout<<cnt<<endl;
	}

	return 0;
}


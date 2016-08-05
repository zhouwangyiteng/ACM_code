/*************************************************************************
	> File Name: hdoj1410.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月05日 星期五 13时39分03秒
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


int main()
{
	int h1,h2,a1,a2;
	while(cin>>h1>>h2>>a1>>a2)
	{
		double ans=0.0;
		int a=h1/a2+!!(h1%a2);
		int b=h2/a1+!!(h2%a1);
		double w1,w2;
		ans=pow(0.5,b);
		double tmp=0.0;
		for(int i=1;i<a;i++)
		{
			tmp+=log10((b-1+i)*1.0)-log10(1.0*i);
			ans+=pow(10,tmp+(b+i)*log10(0.5));
		}
		printf("%.4lf\n",100.0*ans);
	}

	return 0;
}


/*************************************************************************
	> File Name: cvs1200.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月23日 星期五 20时42分51秒
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

LL x,y,a,b;

void exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
}

int main()
{
	scanf("%lld%lld",&a,&b);
	exgcd(a,b,x,y);
	printf("%lld\n",(b+x)%b);

	return 0;
}


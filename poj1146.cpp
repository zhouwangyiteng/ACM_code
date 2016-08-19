/*************************************************************************
	> File Name: poj1146.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月19日 星期五 19时05分55秒
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
#define N 55
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

char str[N];

int main()
{
	while(scanf("%s",str),str[0]!='#')
	{
		if(next_permutation(str, str + strlen(str)))
			printf("%s\n",str);
		else
			printf("No Successor\n");
	}

	return 0;
}


/*************************************************************************
	> File Name: ICPC2016qingdao/1005.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月17日 星期六 12时21分32秒
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

int t,n;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n&1)
			printf("%s\n","Balanced");
		else
			printf("%s\n","Bad");
		
	}

	return 0;
}


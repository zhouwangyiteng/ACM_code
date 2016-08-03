#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;
#define INF 0x3f3f3f3f
#define N 2000
#define CLR(a,x) memset(a,x,sizeof(a))
#define lowbit(x) (x&-x) 

char str[N];
int n,len;

int dfs(int s,int t)
{
	if(t-s+1==1)
	{
		if(str[s]=='1')
		{
			printf("I");
			return 1;
		}
		else
			printf("B");
		return 0;
	}
	int mid=(s+t)/2;
	int a=dfs(s,mid);
	int b=dfs(mid+1,t);
	if(a!=b||a<0||b<0)
	{
		printf("F");
		return -1;
	}
	else
		if(a==1)
			printf("I");
		else
			printf("B");
	return a;
	
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",str);
		len=strlen(str);
		dfs(0,len-1);
		printf("\n");
	}
	
	return 0;
}


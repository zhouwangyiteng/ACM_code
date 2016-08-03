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
#define N 10000
#define CLR(a,x) memset(a,x,sizeof(a))
#define lowbit(x) (x&-x) 

int m,n;

long long f(int m,int n)
{
	if(m==0||n==0)return 1;
	if(m<n) return f(m,m);
	else if(m==1||n==1) return 1;
	else return f(m-n,n)+f(m,n-1);
}

int main()
{
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		cout<<f(m,n)<<endl;
	}
	
	return 0;
}


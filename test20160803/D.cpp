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
#define N 60
#define CLR(a,x) memset(a,x,sizeof(a))
#define lowbit(x) (x&-x) 

int vis[N];
int s,d;

int main()
{
	while(scanf("%d %d",&s,&d),s&&d)
	{
		CLR(vis,0);
		int flag=0;
		int ans=0;
		while(s!=0)
		{
			vis[s]=1;
			s=(s+s*d)%60;
			ans++;
			if(vis[s])
			{
				flag=1;
				break;
			}	
		}
		if(flag)
			cout<<"Impossible"<<endl;
		else
			cout<<ans<<endl;
	}
	
	return 0;
}


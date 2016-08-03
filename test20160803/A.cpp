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

int n,ans;
priority_queue<int, vector<int>, greater<int> > que;

int main()
{
	while(scanf("%d", &n)!=EOF)
	{
		while(!que.empty())
			que.pop();
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			que.push(x);
		}
		ans=0;
		while(que.size()>1)
		{
			int a=que.top();
			que.pop();
			int b=que.top();
			que.pop();
			que.push(a+b);
			ans+=a+b;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}


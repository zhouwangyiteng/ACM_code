/*************************************************************************
	> File Name: 2016CCPC/1011.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月14日 星期日 12时08分28秒
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
#define N 100005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

char str[N];
int t;
map<char,int> mp;
int num[N];
int dp[N];

int main()
{
	cin>>t;
	for(int icase=1;icase<=t;icase++)
	{
		mp.clear();
		scanf("%s",str);
		int len=strlen(str);
		int p=1;
		for(int i=0;i<len;i++)
			if(!mp[str[i]])
			{
				mp[str[i]]=p;
				num[i]=p;
				p++;
			}
			else
				num[i]=mp[str[i]];
		CLR(dp,0x3f);
	    int ans = 1;
	    dp[0] = num[0];
	    for (int i = 1; i < len; i++)
	    {
	        int pos = lower_bound(dp, dp + len, num[i]) - dp;
	        dp[pos] = num[i];
	        ans = max(ans, pos+1);
	    }
	    printf("Case #%d: %d\n",icase,ans);
	}

	return 0;
}


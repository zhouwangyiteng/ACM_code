/*************************************************************************
	> File Name: ICPC2016shenyang/1007.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月18日 星期日 13时20分16秒
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

int ans,t;
LL l,r;

bool yes(int a)
{
	int f,cnt,tmp;
	tmp=a%10;
	a/=10;
	cnt=1;
	f=tmp&1;
	while(a>0)
	{
		// cout<<f<<' '<<cnt<<endl;
		tmp=a%10;
		if((tmp&1)==f)
			cnt++;
		else
		{
			if((cnt&1)==f)
				return false;
			f=tmp&1;
			cnt=1;
		}
		a/=10;
	}
	if((cnt&1)==f)
		return false;
	return true;
}

int main()
{
	scanf("%d",&t);
	for(int icase=1;icase<=t;icase++)
	{
		scanf("%lld%lld",&l,&r);
		ans=0;
		for(int i=l;i<=r;i++)
			if(yes(i))
				ans++;
		printf("Case #%d: %d\n",icase,ans);
	}

	return 0;
}


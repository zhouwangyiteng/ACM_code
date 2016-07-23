/*************************************************************************
	> File Name: poj3061.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月23日 星期六 09时50分21秒
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
#define INF 0x3f3f3f
#define MAXN 1000000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[MAXN];
int n;
map<int,int> mp;
set<int> num;

int main()
{
	scanf("%d",&n);
	mp.clear();
	num.clear();
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		num.insert(a[i]);
	}
	int sum,i,j,ans,s;
	s=num.size();
	ans=n+1;i=0;j=0;sum=0;
	while(1)
	{
		while(sum<s&&j<n)
		{
			if(mp[a[j]]==0)
				sum++;
			mp[a[j]]++;
			j++;
		}
		if(sum<s)
			break;
		ans=min(ans,j-i);
		mp[a[i]]--;
		if(mp[a[i]]==0)
			sum--;
		i++;
	}
	if(ans>n)
		ans=0;
	cout<<ans<<endl;
	

	return 0;
}


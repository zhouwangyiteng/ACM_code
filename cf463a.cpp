/*************************************************************************
	> File Name: cf463a.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月29日 星期四 20时39分03秒
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

int n,s;
int a,b,ans;

int main()
{
	scanf("%d%d",&n,&s);
	ans=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a<=s&&b==0)
			ans=max(ans,0);
		if(a<s&&b!=0)
			ans=max(ans,100-b);
	}
	cout<<ans<<endl;

	return 0;
}


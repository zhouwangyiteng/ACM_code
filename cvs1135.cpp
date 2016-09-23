/*************************************************************************
	> File Name: cvs1135.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月23日 星期五 20时29分45秒
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
#define N 105
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n,k,p,x,y,i,j,f,ans;
int a[N],b[N],c[N];

int main()
{
	scanf("%d%d%d",&n,&k,&p);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(y<=p)
			f=i;
		if(f>=c[x])
			b[x]=a[x];
		ans+=b[x];
		a[x]++;
		c[x]=i;
	}
	cout<<ans<<endl;

	return 0;
}


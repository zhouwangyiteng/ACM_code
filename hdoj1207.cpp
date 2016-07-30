/*************************************************************************
	> File Name: hdoj1207.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月30日 星期六 19时50分41秒
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
#define INF 0x3f3f3f3f
#define N 66
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int n;
double ans[N];

int main()
{
	ans[1]=1;
	ans[2]=3;
	for(int i=3;i<N;i++)
	{
		ans[i]=INF;
		for(int j=1;j<i;j++)
			ans[i]=min(ans[i],2*ans[j]+pow(2,i-j)-1);
	}
	while(cin>>n)
		cout<<ans[n]<<endl;

	return 0;
}


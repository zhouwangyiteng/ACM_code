/*************************************************************************
	> File Name: 2016MUTC4/1010.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月28日 星期四 20时01分00秒
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
#define N 100010
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N],m[N];
int t,n;

int main()
{
	// freopen("1010.in","r",stdin);
	cin>>t;
	for(int icase=1;icase<=t;icase++)
	{
		cin>>n;
		int cnt=0,j=1;
		for(int i=1;i<=n;i++)
		{
			// scanf("%d",a+j);
			cin>>a[j];
			if(a[j]==0)
				cnt++;
			else
			{
				a[j]-=cnt;
				j++;
			}
		}
		CLR(m,0x3f);
		n=j-1;
		int len=0;
		for(int i=1;i<=n;i++)
		{
			int p=lower_bound(m+1,m+n+1,a[i])-m;
			len=max(len,p);
			m[p]=a[i];
		}
		cout<<"Case #"<<icase<<": ";
		cout<<len+cnt<<endl;
	}

	return 0;
}


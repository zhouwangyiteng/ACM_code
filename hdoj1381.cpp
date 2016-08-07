/*************************************************************************
	> File Name: hdoj1381.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月07日 星期日 09时59分32秒
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
#define N 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

set<string> SET;
string str;
int n,nc;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&nc);
		cin>>str;
		int len=str.length();
		for(int i=0;i<=len-n;i++)
		{
			string tmp=string(str,i,n);
			SET.insert(tmp);
		}
		cout<<SET.size()<<endl;
	}

	return 0;
}


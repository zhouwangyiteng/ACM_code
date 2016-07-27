/*************************************************************************
	> File Name: poj1961.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年07月27日 星期三 15时19分07秒
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
#define N 1000005
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))
 
char str[N];
int num[N];

int main()
{
	int n;
	int icase=0;
	while(scanf("%d",&n),n)
	{
		scanf("%s",str);
		int n=strlen(str);
		int j=-1;
		memset(num,0,sizeof(num));
		num[0]=-1;
		for(int i=0;i<n;)
		{
			if(j==-1||str[i]==str[j]) num[++i]=++j;
			else
				j=num[j];
		}
		cout<<"Test case #"<<++icase<<endl;
		for(int i=1;i<=n;i++)
			if(num[i]!=0&&i%(i-num[i])==0)
				cout<<i<<' '<<i/(i-num[i])<<endl;
		cout<<endl;
	}  

	return 0;
}


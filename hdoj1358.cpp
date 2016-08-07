/*************************************************************************
	> File Name: hdoj1358.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月07日 星期日 15时30分31秒
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

int n;
int Next[N];
char str[N];

int main()
{
	int icase=0;
	while(cin>>n,n)
	{
		scanf("%s",str);
		int j=-1;
		Next[0]=-1;
		for(int i=0;i<n;)
			if(j==-1||str[i]==str[j])
				Next[++i]=++j;
			else
				j=Next[j];
		printf("Test case #%d\n",++icase);
		for(int i=1;i<=n;i++)
			if(Next[i]!=0&&i%(i-Next[i])==0)
				printf("%d %d\n",i,i/(i-Next[i]));
		cout<<endl;
	}

	return 0;
}


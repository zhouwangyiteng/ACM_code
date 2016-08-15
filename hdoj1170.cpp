/*************************************************************************
	> File Name: hdoj1170.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月15日 星期一 21时54分14秒
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
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define REP(x,y) for(int x=0;x<y;x++)
#define RDP(x,y) for(int x=y;x>=0;x--)
#define RRP(x,L,R) for(int x=L;x<=R;x++)
#define CLR(A,X) memset(A,X,sizeof(A))

int t,a,b;
char ch;

int main()
{
	cin>>t;
	while(t--)
	{
		getchar();
		scanf("%c",&ch);
		scanf("%d %d",&a,&b);
		if(ch=='+')
			cout<<a+b<<endl;
		else if(ch=='-')
			cout<<a-b<<endl;
		else if(ch=='*')
			cout<<a*b<<endl;
		else
		{
			if(a%b==0)
				cout<<a/b<<endl;
			else
				printf("%.2f\n",1.0*a/b);
		}
	}

	return 0;
}


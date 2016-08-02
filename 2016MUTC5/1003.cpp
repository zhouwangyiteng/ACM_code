/*************************************************************************
	> File Name: 2016MUTC5/1003.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月02日 星期二 12时32分13秒
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

long long a[1000020];

int main()
{
    int t,n;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        int sum=0;
        long long num=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=n;i>=1;i--)
        	if(a[i]>=0)
            {
                sum++;
                a[i]=0;
            }
       		else
            {
                num=a[i];
                a[i-1]+=num;
           	}
        printf("%d\n",sum);
    }

    return 0;
}





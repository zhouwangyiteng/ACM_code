/*************************************************************************
	> File Name: cvs1080.cpp
	> Author:
	> Mail:
	> Blog:
	> Created Time: 2016年09月23日 星期五 19时25分36秒
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
#define N 100005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int b[N];
int n,m,t,x,y;

int lowbit(int i)
{
    return i&(-i);
}

void add(int a,int x)
{
    while(a<=n)
    {
        b[a]+=x;
        a+=lowbit(a);
    }
}

int sum(int a)
{
    int res=0;
    while(a>0)
    {
        res+=b[a];
        a-=lowbit(a);
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        add(i,t);
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d%d",&t,&x,&y);
        if(t==1)
            add(x,y);
        else
            cout<<(sum(y)-sum(x-1))<<endl;
    }

	return 0;
}


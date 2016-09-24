/*************************************************************************
	> File Name: cf719c.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月24日 星期六 08时25分08秒
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
#define N 200005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int a[N],n,t,p,tail;
char ch;

int main()
{
	scanf("%d%d",&n,&t);
	getchar();
	p=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&ch);
		if(ch=='.')
		{
			p=i;
			a[i]=0;
			continue;
		}
		a[i]=ch-'0';
	}
	tail=p+1;
	while(a[tail]<5&&tail<=n)
		tail++;
	if(tail<=n)
	{
		while(a[tail]>=5&&t>0)
		{
			a[tail-1]+=1;
			t--;
			tail--;
		}
	}
	else
		tail=n;
	if(tail==p)
	{
		int i=p-1;
		a[i]++;
		while(a[i]>9)
		{
			a[i]%=10;
			i--;
			a[i]++;
		}
	}
	if(a[0]>0)
		printf("%d",a[0]);
	for(int i=1;i<p;i++)
		printf("%d",a[i]);
	if(tail>p)
		printf(".");
	for(int i=p+1;i<=tail;i++)
		printf("%d",a[i]);
	printf("\n");

	return 0;
}


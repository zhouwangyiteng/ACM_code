/*************************************************************************
	> File Name: cf508b.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月29日 星期四 21时10分49秒
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

char str[N];
int a[N];
int n;



int main()
{
	scanf("%s",str);
	n=strlen(str);
	for(int i=0;i<n;i++)
		a[i]=(int)(str[i]-'0');
	int f=-1;
	for(int i=0;i<n-1;i++)
		if(!(a[i]&1)&&a[i]<a[n-1])
		{
			a[i]^=a[n-1];
			a[n-1]^=a[i];
			a[i]^=a[n-1];
			f=1;
			break;
		}
	if(f>0)
	{
		for(int i=0;i<n;i++)
			printf("%d",a[i]);
		printf("\n");
		return 0;
	}
	for(int i=n-2;i>=0;i--)
		if(!(a[i]&1))
		{
			a[i]^=a[n-1];
			a[n-1]^=a[i];
			a[i]^=a[n-1];
			f=1;
			break;
		}
	if(f>0)
	{
		for(int i=0;i<n;i++)
			printf("%d",a[i]);
		printf("\n");
		return 0;
	}
	printf("-1\n");

	return 0;
}


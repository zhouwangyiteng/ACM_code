/*************************************************************************
	> File Name: cf719a.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月23日 星期五 21时08分07秒
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
#define N 100
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n;
int a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	int f=0;
	if(n==1)
	{
		if(a[1]==0)
			f=1;
		else if(a[1]==15)
			f=-1;
		else
			f=0;
	}
	else 
	{
		if(a[n]==0&&a[n-1]==1)
			f=1;
		else if(a[n]==15&&a[n-1]==14)
			f=-1;
		else if(a[n]>a[n-1])
			f=1;
		else if(a[n]<a[n-1])
			f=-1;
		else
			f=0;
	}
	if(f==0)
		cout<<-1<<endl;
	else if(f==1)
		cout<<"UP"<<endl;
	else
		cout<<"DOWN"<<endl;

	return 0;
}


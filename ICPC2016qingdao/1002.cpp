/*************************************************************************
	> File Name: ICPC2016qingdao/1002.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月17日 星期六 12时28分55秒
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
#define N 1000005
#define M 100000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

string n;
double a[N];

int sStoi(string str)
{
	int tmp=0;
	int len=str.length();
	for(int i=0;i<len;i++)
	{
		tmp*=10;
		tmp+=str[i]-'0';
	}
	return tmp;
}

int main()
{
	CLR(a,0);
	for(int i=1;i<1000000;i++)
	{
		a[i]=a[i-1]+1.0/i*(1.0/i);
	}
	while(cin>>n)
	{
		if(n.length()>=7)
			printf("1.64493\n");
		else
		{
			printf("%.5f\n",a[sStoi(n)]);
		}
	}

	return 0;
}


/*************************************************************************
	> File Name: cf320a.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月29日 星期四 21时38分54秒
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
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

int n;
int f;

int main()
{
	scanf("%d",&n);
	f=0;
	while(n>0)
	{
		if(n%10==1)
			n/=10;
		else if(n%100==14)
			n/=100;
		else if(n%1000==144)
			n/=1000;
		else
		{
			f=1;
			break;
		}
	}
	if(f)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;

	return 0;
}


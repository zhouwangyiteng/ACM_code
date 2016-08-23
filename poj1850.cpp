/*************************************************************************
	> File Name: poj1850.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月23日 星期二 21时30分15秒
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

int c[27][27];
char str[15];

void init()
{
	for(int i=0;i<27;i++)
		for(int j=0;j<=i;j++)
			if(!j||i==j)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
	c[0][0]=0;
}

int main()
{
	init();
	while(scanf("%s",str)!=EOF)
	{
		int len=strlen(str);
		for(int i=1;i<len;i++)
			if(str[i]<=str[i-1])
			{
				cout<<0<<endl;
				return 0;
			}
		int sum=0;
		for(int i=1;i<len;i++)
			sum+=c[26][i];
		for(int i=0;i<len;i++)
		{
			char ch=(!i)?'a':str[i-1]+1;
			while(ch<=str[i]-1)
			{
				sum+=c['z'-ch][len-i-1];
				ch++;
			}
		}
		cout<<++sum<<endl;
	}

	return 0;
}


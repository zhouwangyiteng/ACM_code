/*************************************************************************
	> File Name: cf435b.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月11日 星期日 20时24分44秒
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
#define N 20
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

char str[N];
int n;
int k;

void SWAP(int i,int j)
{
	char ch;
	ch=str[i];
	str[i]=str[j];
	str[j]=ch;
}

int main()
{
	scanf("%s %d",str,&k);
	n=strlen(str);
	int bg=0;
	while(k>0)
	{
		char m=str[bg];
		int p=bg;
		if(bg==n)
			break;
		for(int i=bg+1;i<=bg+k&&i<n;i++)
			if(str[i]>m)
			{
				m=str[i];
				p=i;
			}
		for(int i=p;i>bg;i--)
			str[i]=str[i-1];
		str[bg]=m;
		k-=(p-bg);
		bg++;
	}
	for(int i=0;i<n;i++)
		printf("%c",str[i]);
	printf("\n");

	return 0;
}


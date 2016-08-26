/*************************************************************************
	> File Name: hdoj1020.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月26日 星期五 21时25分30秒
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
#define N 10005
#define M 1000
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))

char str[N];
int n,t;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		n=strlen(str);
		int cur=1;
		char ch=str[0];
		for(int i=1;i<n;i++)
		{
			if(str[i]!=ch)
			{
				if(cur==1)
					printf("%c",ch);
				else
					printf("%d%c",cur,ch);
				ch=str[i];
				cur=1;
			}
			else
				cur++;
		}
		if(cur==1)
			printf("%c",ch);
		else
			printf("%d%c",cur,ch);
		printf("\n");
	}

	return 0;
}


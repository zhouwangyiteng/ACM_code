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
#include <fstream>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define CLR(a,x) memset(a,x,sizeof(a))
#define LL long long
#define INF 0X3FFFF
#define N 2005
#define M 1000000
using namespace std;

int a[N];
int f[105];
int n;

int main()
{
	while(cin>>n)
	{
		CLR(f,0);
		for(int i=0;i<n;i++)
		{
			scanf("%d",a+i);
			f[a[i]]++;
		}
		int flag=1;
		for(int i=0;i<n;i++)
			if(f[a[i]]==1)
			{
				printf("%d\n",a[i]);
				flag=0;
				break;
			}
		if(flag)
			cout<<-1<<endl;
	}
	
	return 0;
}


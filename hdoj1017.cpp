/*************************************************************************
	> File Name: hdoj1017.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年08月26日 星期五 21时10分28秒
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

int n,m;
int cnt;

int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
		int icase=0;
		while(cin>>n>>m,n||m)
		{
			cnt=0;
			for(int i=1;i<n;i++)
				for(int j=i+1;j<n;j++)
					if((i*i+j*j+m)%(i*j)==0)
						cnt++;
			printf("Case %d: %d\n",++icase,cnt);
		}
		if(tt>0)
			cout<<endl;
	}

	return 0;
}


#include<vector>
#include<cmath>
#include<algorithm>
#include <map>
#include <iostream>

using namespace std;
#define MAXN 1000
#define INF 0x3f3f3f3f

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int cnt=n/4;
		int x=cnt,y=cnt;
		while(x>=4||y>=2)
		{
			int tx=x/4,ty=y/2;
			cnt+=(tx+ty);
			x=x%4+tx+ty;
			y=y%2+tx+ty;
		}
		cout<<cnt<<endl;
	}

	return 0;
}
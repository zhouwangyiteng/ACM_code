#include<vector>
#include<cmath>
#include<algorithm>
#include <map>
#include <iostream>

using namespace std;
#define MAXN 1000
#define INF 0x3f3f3f3f

long long com(int n,int r)
{
	long long i,j,s=1;
	for(i=n;i>n-r;i--)
	{
		s*=i;
	}
	return s;
}

long long f(int n)
{
	long long ans=1;
	for(int i=2;i<=n;i++)
		ans*=i;
	return ans;
}

int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		cout<<f(n-1)*com(n,m)<<endl;
	}	

	return 0;
}
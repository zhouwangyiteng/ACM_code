#include<vector>
#include<cmath>
#include<algorithm>
#include <map>
#include <iostream>

using namespace std;
#define MAXN 1000
#define INF 0x3f3f3f3f

int t;
double a,b;

int main()
{
	cin>>t;
	double h=155.5;
	while(t--)
	{
		cin>>a>>b;
		printf("%.2lf\n",b*h/a);
	}

	return 0;
}
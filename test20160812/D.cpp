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
#define N 1000000
#define M 1000000
using namespace std;

double x[4],y[4];

int main()
{
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])!=EOF)
	{
		if(x[0]>x[1])
		{
			int t=x[0];
			x[0]=x[1];
			x[1]=t;
		}
		if(x[2]>x[3])
		{
			int t=x[2];
			x[2]=x[3];
			x[3]=t;
		}
		if(y[0]>y[1])
		{
			int t=y[0];
			y[0]=y[1];
			y[1]=t;
		}
		if(y[2]>y[3])
		{
			int t=y[2];
			y[2]=y[3];
			y[3]=t;
		}
		double a=max(x[0],x[2]);
		double b=min(x[1],x[3]);
		double c=max(y[0],y[2]);
		double d=min(y[1],y[3]);
		if(a>=b||c>=d)
		{
			printf("0.00\n");
			continue;
		}
		printf("%.2lf\n",(b-a)*(d-c));
	}
	
	return 0;
}


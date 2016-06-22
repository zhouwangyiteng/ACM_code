#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 65536
double L,l,C,n,cta,R;
double f(double ct)
{
	return L*sin(ct)/ct;
}

int main()
{
    while(cin>>l>>n>>C)
    {
		if(l<0||n<0||C==-1) break;
		if(n==0)
		{
			printf("%0.3f\n",0.0);
			continue;
		}
		L=(1+n*C)*l;
		double low=0,high=1.52;
		while((high-low)>1e-10)
		{
			cta=(low+high)/2;
			if(f(cta)>l) low=cta;
			else high=cta;
		}
		R=L/(2*cta);
		printf("%0.3f\n",R-sqrt(R*R-l*l/4));
	}
    
	return 0;  
}    

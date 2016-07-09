#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define MAXN 1005

int n;
double a[MAXN];
int d1[MAXN],d2[MAXN];

int main() 
{
    while(cin>>n)
    {
     	for(int i=0;i<n;i++)
     		cin>>a[i];
     	d1[0]=1;
     	for(int i=1;i<n;i++)
     	{
     		int m=0;
     		for(int j=0;j<i;j++)
     			if(a[j]<a[i]&&m<d1[j]) m=d1[j];
     		d1[i]=m+1;
     	}
     	d2[n-1]=1;
     	for(int i=n-2;i>=0;i--)
     	{
     		int m=0;
     		for(int j=n-1;j>i;j--)
     			if(a[j]<a[i]&&m<d2[j]) m=d2[j];
     		d2[i]=m+1;
     	}
     	int ans=0;
     	for(int i=0;i<n;i++)
     		for(int j=i+1;j<n;j++)
     			ans = ans>(d1[i]+d2[j])?ans:(d1[i]+d2[j]);
     	cout<<n-ans<<endl;
    }


	return 0;
}
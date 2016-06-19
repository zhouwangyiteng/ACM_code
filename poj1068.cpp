#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>//sortËùÔÚ¿â£¬ÅÅÐòÓÃ
using namespace std;
#define MAXN 1000
int w[MAXN];
int a[MAXN];


int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
		cin>>n;
		int top=0, sum=0, p;
		for(int i=1; i<=n;i++)
		{
			cin>>p;
			for(int j=0;j<p-sum;j++)
			{
				a[top++]=-1;
			}
			a[top++]=1;
			sum=p;
			int j=top-1;
			while(a[j]>=0)
			{
				if(a[j]>0)
					a[top-1]++;
				j--;
			}
			a[j]=0;
		}
		for(int i=0;i<top;i++)
			if(a[i]>0)
				cout << a[i]-1 <<' ';
		cout << endl;
	}
    
	return 0;  
}    

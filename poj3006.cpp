#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 65536

bool Prime(int n)
{
	int e=(int)(sqrt(0.0+n)+1);
	for(int i=2;i<e;i++)
		if(n%i==0)
			return false;
	if(n==1) 
		return false;
	return true;
}

int main()
{
    int a,d,n;
    while(cin>>a>>d>>n)
    {
		if(a==0&&d==0&&n==0) break;
		int cnt=0;
		while(cnt<n)
		{
			if(Prime(a))
				cnt++;
			a+=d;
		}
		cout<<a-d<<endl;
	}
    
	return 0;  
}    

#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 10001

int num[MAXN];
int t,k;
void FindK(int l,int r)
{
	int mid=num[l];
	int i=l,j=r;
	while(i<j)
	{
		while(i<j&&num[j]>=mid) j--;
		if (i < j) num[i++] = num[j];
		while(i<j&&num[i]<=mid) i++;
		if (i < j) num[j--] = num[i];
	}
	num[i]=mid;
	if(i==k)
		return;
	else
		if(i<k)
			FindK(i+1, r);
		else
			FindK(l,i-1);
	
}

int main()
{
	cin>>t;
	for(int i=1;i<=t;i++)
		scanf("%d",&num[i]);
	k=(t+1)/2;
	FindK(1,t);
	cout<<num[k]<<endl;	 
    
	return 0;  
}    

#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 500001

int num[MAXN],c[MAXN];
long long cnt;

void MergeSort(int l,int r)
{
	int mid,i,j,tmp;
	if(l+1<r)
	{
		mid=(l+r)/2;
		MergeSort(l,mid);
		MergeSort(mid,r);
		tmp=l;
		for(i=l,j=mid;i<mid&&j<r;)
		{
			if(num[i]>num[j])
			{
				c[tmp++]=num[j++];
				cnt+=mid-i;
			}
			else
	 			c[tmp++]=num[i++];
		}
		if(j<r) for(;j<r;++j) c[tmp++]=num[j];
		else for(;i<mid;++i) c[tmp++]=num[i];
		for(i=l;i<r;++i)
			num[i]=c[i];
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		cnt=0;
		MergeSort(0,n);
		cout<<cnt<<endl;
	}	 
    
	return 0;  
}    

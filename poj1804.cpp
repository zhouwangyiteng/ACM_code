#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 1001

int a[MAXN],c[MAXN];
int t,n,cnt;

void MergeSort(int l,int r)
{
	if(l+1<r)
	{
		int i,j,tmp,mid;
		mid=(l+r)/2;
		MergeSort(l,mid);
		MergeSort(mid,r);
		tmp=l;
		for(i=l,j=mid;i<mid&&j<r;)
		{
			if(a[i]>a[j])
			{
				c[tmp++]=a[j++];
				cnt+=mid-i;
			}
			else
				c[tmp++]=a[i++];
		}
		if(j<r) for(;j<r;j++) c[tmp++]=a[j];
		else for(;i<mid;i++) c[tmp++]=a[i];
		for(i=l;i<r;i++)
			a[i]=c[i];
	}
}

int main()
{
	cin>>t;
	int icase=0;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		cnt=0;
		MergeSort(0,n);
		cout<<"Scenario #"<<++icase<<":"<<endl;
		cout<<cnt<<endl<<endl;
	}    
    
	return 0;  
}    

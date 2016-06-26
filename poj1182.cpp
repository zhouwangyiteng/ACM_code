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
struct node
{
	int p;
	int r;
}set[MAXN];


int Find(int v)
{
	int temp;
	if(v==set[v].p)
		return v;
	temp=set[v].p;
	set[v].p=Find(temp);
	set[v].r=(set[v].r+set[temp].r)%3;
	return set[v].p;
}


int main()
{
    int n,k,root1,root2,cnt=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
		set[i].p=i;
		set[i].r=0;
	}
    while(k--)
    {
		int d,x,y;
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n)
		{
			cnt++;
			continue;
		}
		if(d==2&&x==y)
		{
			cnt++;
			continue;
		}
		root1=Find(x);
		root2=Find(y);
		if(root1!=root2)
		{
			set[root2].p=root1;
			set[root2].r=(3+d-1+set[x].r-set[y].r)%3;
		}
		else
    	{
			if(d==1&&set[x].r!=set[y].r)
			{
				cnt++;
				continue;
			}
			if(d==2&&((3-set[x].r+set[y].r)%3!=d-1))
			{
				cnt++;
				continue;
			}
		}
	}
	cout<<cnt<<endl;
    
	return 0;  
}    

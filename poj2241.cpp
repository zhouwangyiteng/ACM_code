#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 31

struct node
{
	int x,y,z;
    node(int a=0,int b=0,int c=0):x(a),y(b),z(c){}
	bool operator < (const node &a)const  
    {  
    	return x<a.x;  
    }
};
int n,icase,h,dp[MAXN*3];
node d[MAXN*3];

int main()
{
    icase=0;
    while(cin>>n)
    {
		if(n==0)
			break;
		int cur=0;
		for(int i=0;i<n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			d[cur++]=node(max(a,b),min(a,b),c);
			d[cur++]=node(max(a,c),min(a,c),b);
			d[cur++]=node(max(c,b),min(c,b),a);
		}
		sort(d,d+cur);
		h=0;
		for(int i=0;i<cur;i++)
		{
			int imax=0;
			for(int j=i-1;j>=0;j--)
				if(d[i].x>d[j].x&&d[i].y>d[j].y)
					imax=max(imax,dp[j]);
			dp[i]=imax+d[i].z;
			h=max(h,dp[i]);
		}	
		cout<<"Case "<<++icase<<": maximum height = "<<h<<endl;	
	}
    
	return 0;  
}    

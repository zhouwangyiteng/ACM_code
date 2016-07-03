#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 100005
#define INF 0x3f3f3f3f

int t,n;

int main()
{
	cin>>t;
	int icase=0;
	while(t--)    
    {
    	cin>>n;
    	int start=1,flag=1,end=n,cnt=0,ans=-INF,num;
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d",&num);
    		cnt+=num;
			if(cnt>=ans)
			{
				ans=cnt;
				start=flag;
				end=i;
			}	
			if(cnt<0)
			{
				cnt=0;
				flag=i+1;
			}
    		
    	}
		cout<<"Case "<<++icase<<":"<<endl;
		printf("%d %d %d\n",ans,start,end);
		if(t)
			cout<<endl;
	}
	return 0;  
}    

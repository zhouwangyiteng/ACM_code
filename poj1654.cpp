#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 1000005

int dir[10][2]={0,0,1,-1,1,0,1,1,0,-1,0,0,0,1,-1,-1,-1,0,-1,1};
char s[MAXN];
__int64 area,x,y,px,py;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
		cin>>s;
		int nlen=strlen(s);
		if(nlen<3)
		{
			cout<<0<<endl;
			continue;
		}
		area=x=y=0;
		for(int i=0;i<nlen;i++)
		{
			px=x+dir[s[i]-'0'][0];
			py=y+dir[s[i]-'0'][1];
			area+=px*y-py*x;
			x=px;
			y=py;
		}
		if(area<0) area*=-1;
		if(area&1)
			printf("%I64d.5\n",area/2);
		else
			cout<<area/2<<endl;
	}
    
	return 0;  
}    

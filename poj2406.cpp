#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 1000001
int num[MAXN];
char str[MAXN];

int main()
{
	while(scanf("%s",&str),str[0]!='.')
	{
		int n=strlen(str);
		int j=-1;
		memset(num,0,sizeof(num));
		num[0]=-1;
		for(int i=0;i<n;)
		{
			if(j==-1||str[i]==str[j]) num[++i]=++j;
			else
				j=num[j];
		}
		if(n%(n-num[n])==0)
			cout<<n/(n-num[n])<<endl;
		else
			cout<<1<<endl;
	}    
    
	return 0;  
}    

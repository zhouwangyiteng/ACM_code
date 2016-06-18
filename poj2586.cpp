#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>//sortËùÔÚ¿â£¬ÅÅÐòÓÃ
using namespace std;
#define MAXN 65536


int main()
{
    int s, d, res;
    while(cin>>s>>d)
    {
    	res=0;
		if(d>4*s) res=10*s-2*d;
		else if(2*d>3*s) res=8*s-4*d;
		else if(3*d>2*s) res=6*(s-d);
		else if(4*d>s) res=3*s-9*d;
		else res=-1;
		if(res<0) 
			cout<<"Deficit"<<endl;
		else
			cout<<res<<endl;
	}
    
	return 0;  
}    

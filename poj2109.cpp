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
    double n, p;
    while(cin>>n>>p)
    {
		cout << pow(p, 1/n) << endl;
	}
    
	return 0;  
}    

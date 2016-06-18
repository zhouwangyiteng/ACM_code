#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>//sortËùÔÚ¿â£¬ÅÅĞòÓÃ
using namespace std;
#define MAXN 1005
struct Line
{
	double l, r;
}line[MAXN];
bool cmp(Line a, Line b)
{
	return a.l<b.l;
}


int main()
{
    int n, d, x, y, i, icase=1;
    bool yes;
    while(cin>>n>>d)
    {
    	yes = true;
    	int cnt = 0;
		if(n==0&&d==0) break;
		for(i=0; i<n; i++)
		{
			cin >> x >> y;
			if(yes==false) continue;
			if(y>d) 
				yes=false;
			else
			{
				line[i].l = (double)x - sqrt((double)d*d-(double)y*y);
				line[i].r = (double)x + sqrt((double)d*d-(double)y*y);
			}
		}
		if(yes==false)
		{
			cout<<"Case "<<icase++<<": "<<-1<<endl;
			continue;
		}
		sort(line,line+n,cmp);
		cnt++;
		double now=line[0].r;
		for(i=1; i<n; i++)
		{
			if(line[i].r<now)
				now=line[i].r;
			else
				if(now<line[i].l)
				{
					now=line[i].r;
					cnt++;
				}
		}
		cout<<"Case "<<icase++<<": "<<cnt<<endl;
	}
    
	return 0;  
}    

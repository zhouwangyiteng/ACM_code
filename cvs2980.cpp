/*************************************************************************
	> File Name: cvs2980.cpp
	> Author: 
	> Mail:  
	> Blog: 
	> Created Time: 2016年09月25日 星期日 11时13分18秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
using namespace std;
#define X first
#define Y second
#define LL long long
#define INF 0x3f3f3f3f
#define N 105
#define M 505
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define CLR(A,X) memset(A,X,sizeof(A))


int f[2][M];
struct node
{
	int k;
	string str;
	node(){};
	node(string s)
	{
		str=s;
		memset(f,0,sizeof(f));  
        int now=0;  
        for (int i=s.length()-1;i>=0;i--)  
        {  
            f[now][i]=1;  
            for (int j=i+1;j<s.length();j++)  
                if (s[i]==s[j])  
                    f[now][j]=f[1-now][j-1]+2;  
                else 
                    f[now][j]=max(f[now][j-1],f[1-now][j]);  
            now=1-now;  
        }  
        if (s.length()%2==0)  
            k=f[1][s.length()-1];  
        else 
            k=f[0][s.length()-1];  
	};
};

bool cmp(node a,node b)
{
	if(a.k==b.k)
		return a.str<b.str;
	else
		return a.k>b.k;
}
node a[N];
int n;
string chs;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>chs;
		a[i]=node(chs);
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
		cout<<a[i].str<<endl;

	return 0;
}


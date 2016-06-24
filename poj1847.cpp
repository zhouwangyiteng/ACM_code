#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 101
#define inf 0x3f3f3f3f

int mat[MAXN][MAXN];

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	memset(mat,0x3f,sizeof(mat));
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			int t;
			cin>>t;
			if(j==0)
				mat[i][t]=0;
			else
				mat[i][t]=1;
		}
	} 
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(mat[i][k]+mat[k][j]<mat[i][j])
					mat[i][j]=mat[i][k]+mat[k][j];
	if(mat[a][b]==inf)
		cout<<-1<<endl;
	else
		cout<<mat[a][b]<<endl;
    
	return 0;  
}    

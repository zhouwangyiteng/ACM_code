#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
using namespace std;
const int INF = 999999999;
const int N = 151*151*151;
int k[10],p[10];
int n,m,cnt,mid;

bool used[N];
struct Hash
{
	int val;
	int cnt;
}HashTable[N];
void initHash()
{
	memset(used,false,sizeof(used));
	memset(HashTable,0,sizeof(HashTable));
}
int SearchHash(int v)
{
	int temp=v;
	while(temp<0) temp+=N;
	while(temp>=N) temp-=N;
	while(used[temp]&&HashTable[temp].val!=v)
	{
		temp++;
		if(temp>=N) temp-=N;
	}
	return temp;
}
void InsertHash(int v)
{
	int pos=SearchHash(v);
	HashTable[pos].val=v;
	used[pos]=true;
	HashTable[pos].cnt++;
}

int POW(int a,int n)
{
    int ans = 1;
    while(n)
    {
        if(n&1) ans = ans*a;
        a = a*a;
        n>>=1;
    }
    return ans;
}

void dfs(int step,int ans)
{
	if(step==mid)
	{
		InsertHash(ans);
		return;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			dfs(step+1,ans+k[step]*POW(i,p[step]));
		}
	}
}
void dfs2(int step,int ans)
{
	if(step==n+1)
	{
		ans=-ans;
		int s=SearchHash(ans);
		if(HashTable[s].val==ans)
			cnt+=HashTable[s].cnt;
		return;
	}
	else
	{
		for(int i=1;i<=m;i++)
			dfs2(step+1,ans+k[step]*POW(i,p[step]));
	}
}

int main()
{
    cin>>n>>m;
    if(n==1)
    {
		cout<<0<<endl;
		return 0;
	}
	initHash();
	cnt=0;
	for(int i=1;i<=n;i++)
		cin>>k[i]>>p[i];
	mid=n/2+1;
	dfs(1,0);
	dfs2(mid,0);
	cout<<cnt<<endl;
    
	return 0;  
}    

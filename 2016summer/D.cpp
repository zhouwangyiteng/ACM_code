#include<vector>
#include<cmath>
#include<algorithm>
#include <map>
#include <iostream>

using namespace std;
#define MAXN 1005
#define INF 0x3f3f3f3f

int k,n,cnt;
int used[MAXN];
int rcd[MAXN];

void unrepeat_permutation(int l)
{
	int i;
	if(l==n)
	{
		int flag=1;
		for(int j=1;j<l;j++)
			if()
		cnt++;
		return;
	}
	for(i=0;i<k;i++)
		if(used[i]>0)
		{
			used[i]--;
			rcd[l]=i;
			unrepeat_permutation(l+1);
			used[i]++;
		}
}

int main()
{
	while(cin>>k)
	{
		n=0;
		for(int i=0;i<k;i++)
		{
			cin>>used[i];
			n+=used[i];
		}
		cnt=0;
		unrepeat_permutation(0);
		cout<<cnt%1000000007<<endl;
	}

	return 0;
}
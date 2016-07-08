#include<vector>
#include<cmath>
#include<algorithm>
#include <map>
#include<queue>
#include <iostream>

using namespace std;
#define MAXN 15
#define INF 0x3f3f3f3f

int n,m,cnt,ans;
char ch;

int main()
{
	while(cin>>n>>m)
	{
		cnt=0;
		ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>ch;
				if(ch!='.')
					cnt++;
				else
					if(cnt&1)
						ans++;
			}
		cout<<ans+cnt/2<<endl;
				
	}

	return 0;
}

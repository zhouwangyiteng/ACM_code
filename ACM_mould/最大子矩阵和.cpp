int a[N][N];
int n;
int ans,mx;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		CLR(a,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
				a[i][j]+=a[i-1][j];
			}
		ans=-INF;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				mx=0;
				for(int k=1;k<=n;k++)
				{
					if(mx<=0)
						mx=a[j][k]-a[i][k];
					else
						mx+=a[j][k]-a[i][k];
					ans=max(ans,mx);
				}
			}
		cout<<ans<<endl;
	}

	return 0;
}


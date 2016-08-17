
int a[MAXN],dp[MAXN],m[MAXN];
int t,n;

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			m[i]=INF;
		}
		for(int i=1;i<=n;i++)
		{
			int p=lower_bound(m+1,m+n+1,a[i])-m;
			dp[i]=p;
			m[p]=a[i];
		}
		for(int i=1;i<n;i++)
			printf("%d ",dp[i]);
		printf("%d\n",dp[n]);
	}

	return 0;
}



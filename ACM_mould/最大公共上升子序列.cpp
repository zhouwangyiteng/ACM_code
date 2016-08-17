
int t,n1,n2,l1[N],l2[N],dp[N];

int LCIS()
{
	for(int i=1;i<=n1;i++)
	{
		int k=1;
		for(int j=1;j<=n2;j++)
			if(l1[i]==l2[j])
				dp[j]=max(dp[j],dp[k]+1);
			else 
				if(l1[i]>l2[j]&&dp[k]<dp[j])
					k=j;
	}
	int mx=0;
	for(int i=1;i<=n2;i++)
		mx=max(mx,dp[i]);
	return mx;
}

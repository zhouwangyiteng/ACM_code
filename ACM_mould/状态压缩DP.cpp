int dp[1<<N][N];
int g[N][N];
int n;

int main()
{
	scanf("%d",&n);
	n++;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j&&j!=k&&i!=k)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	CLR(dp,0x3f);
	dp[(1<<n)-1][0]=0;
	for(int s=(1<<n)-2;s>=0;s--)
		for(int v=0;v<n;v++)
			for(int u=0;u<n;u++)
				if(!(s<<u&1))
					dp[s][v]=min(dp[s][v],dp[s|(1<<u)][u]+g[v][u]);
	printf("%d\n",dp[0][0]);
	return 0;
}
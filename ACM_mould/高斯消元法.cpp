//矩阵坐标从1开始计数

int guass(int n)
{
	int i,j,k,r;
	i=j=k=r=0;
	for(i=1,j=1;i<=n&&j<=n;j++)
	{
		k=i;
		while(k<=n&&!a[k][j])
			k++;
		if(a[k][j])
		{
			for(r=1;r<=n+1;r++)
				swap(a[i][r],a[k][r]);
			for(r=1;r<=n;r++)
				if(r!=i&&a[r][j])
					for(k=i;k<=n+1;k++)
						a[r][k]^=a[i][k];
			i++;
		}
	}
	for(j=i;j<=n;j++)
		if(a[j][n+1])
			return -1;
	return 1<<(n-i+1);
}

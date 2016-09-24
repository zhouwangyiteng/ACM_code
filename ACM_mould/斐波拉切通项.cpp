double fpow(double a,int n)
{
	double res=1;
	while(n>0)
	{
		if(n&1)
			res*=a;
		a*=a;
		n>>=1;
	}
	return res;
}

int f(int n)
{
	double t=sqrt(5);
	return (int)((fpow((1+t)/2,n)-fpow((1-t)/2,n))/t);
}

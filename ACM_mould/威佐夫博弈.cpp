int a,b,i;

int main()
{
	while(cin>>a>>b)
	{
		if(a<b)
		{
			a^=b;
			b^=a;
			a^=b;
		}
		int i=a-b;
		a=(int)(i*(1+sqrt(5))/2.0);
		if(a==b)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}

	return 0;
}



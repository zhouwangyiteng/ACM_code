
void getNext()
{
	int j=-1;
	next[0]=-1;
	for(int i=0;i<n;)
		if(j==-1||str[i]==str[j])
			next[++i]=++j;
		else
			j=next[j];
}

void getnext()  
{  
    int i=0,j=-1,l=m;  
    c[0]=-1;  
    while(i<l)  
        if(j==-1||s2[i]==s2[j])  
            c[++i]=++j;  
        else  
            j=c[j];  
}  
int kmp(int x)  
{  
    int i=x,j=0,k=0,len=n,l=m;  
    while(i<len)  
    {  
        if(j==-1|s[i]==s2[j])  
            i+=1,j++;  
        else  
            j=c[j];  
        if(j==l)  
            k++,j=c[j];  
    }  
    return k;  
}  
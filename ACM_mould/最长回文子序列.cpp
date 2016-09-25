int f[2][M];
memset(f,0,sizeof(f));  
int now=0;  
for (int i=s.length()-1;i>=0;i--)  
{  
    f[now][i]=1;  
    for (int j=i+1;j<s.length();j++)  
        if (s[i]==s[j])  
            f[now][j]=f[1-now][j-1]+2;  
        else 
            f[now][j]=max(f[now][j-1],f[1-now][j]);  
    now=1-now;  
}  
if (s.length()%2==0)  
    k=f[1][s.length()-1];  
else 
    k=f[0][s.length()-1];
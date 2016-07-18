#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define MAXN 300

int main()
{
    char str[300];
    char str1[300];
    int pre[300];
    int visited[300];
    int del[300];
    int nCase;
    scanf("%d", &nCase);
    getchar();
    while(nCase--)
    {
        gets(str);
        memset(pre, 0, sizeof(pre));
        memset(visited, 0, sizeof(visited));
        memset(del, 0, sizeof(del));
        int nLen = strlen(str);
        int nCount = 0;
        for (int i = 0; i < nLen; i++)
        {
            if (str[i] != ' ')
            {
                str1[nCount++] = str[i];
            }
        }
        str1[nCount] = '\0';
        nLen = strlen(str1);
        for (int i = 0; i < nLen; i++)
        {
            if (str1[i] == ')')
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (str1[j] == '(' && !visited[j])
                    {
                        pre[i] = j;
                        visited[j] = 1;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < nLen; i++)
        {
            if (str1[i] == ')')
            {
                int flag = 0;
                for (int j = i - 1; j > pre[i]; j--)
                {
                    if (str1[j] == '+' || str1[j] == '-')
                    {
                        flag = 1;
                        break;
                    }
                }
                if (str1[pre[i]] == '(' && (str1[pre[i] - 1] != '-' || pre[i] == 0 || !flag))
                {
                    del[i] = del[pre[i]] = 1;
                }
            }
        }
        for (int i = 0; i < nLen; i++)
        {
            if (!del[i])
            {
                printf("%c", str1[i]); 
            }
        }
        printf("\n");
    }
    return 0;
}

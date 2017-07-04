#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    //..prompts user input of a name
    string s=get_string();
    int i,n;
    //...if no spaces at the start
    if(s[0]!=' ')
    {
        printf("%c",toupper(s[0]));
    }
    
    //....check for space and the next character
    for(i=0,n=strlen(s);i<n-1;i++)
    {
        if(s[i]==' ' && s[i+1]!=' ' )
        {
            printf("%c",toupper(s[i+1]));
        }
    }
    printf("\n");
}
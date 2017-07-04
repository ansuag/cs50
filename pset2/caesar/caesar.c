#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main(int argc, string argv[])
{
    // prints error if command line argument is not given
    if(argc!=2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    
    // convert key from string to int
    int k=atoi(argv[1]);
    
    //prompts user input for a plaintext
    printf("plaintext: ");
    string plaintext=get_string();
    int i,n;
    printf("ciphertext: ");
    
    // encrypts the plaintext with key k
    for(i=0,n=strlen(plaintext);i<n;i++)
    {
        if(isalpha(plaintext[i]))
        {
            // if character in plaintext is uppercase
            if(isupper(plaintext[i]))
            {
                int t=(int)plaintext[i]-65;
                t=((t+k)%26)+65;
                printf("%c",(char)t);
            }
            // if character in plaintext is lowercase
            else if(islower(plaintext[i]))
            {
                int t=(int)plaintext[i]-97;
                t=((t+k)%26)+97;
                printf("%c",(char)t);
            }
        }
        // if character in plaintext is not an alphabet print the same
        else
            printf("%c",plaintext[i]);
        
    }
    printf("\n");
}
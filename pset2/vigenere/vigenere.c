#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
int main(int argc, string argv[])
{
    // prints error if command line argument is not given
    if(argc!=2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    
    // find length of the key
    int length=strlen(argv[1]);
    int key[length];
    
    // convert each character of key into an integer
    for(int m=0;m<length;m++)
    {
        if(isalpha(argv[1][m]))
        {
            if(isupper(argv[1][m]))
            {
                key[m]=(int)argv[1][m]-65;
            }
            else
            {
                key[m]=(int)argv[1][m]-97;
            }
        }
        // if key contains non alphabetical character print error
        else
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }
    
    //prompts user input for plaintext
    printf("plaintext: ");
    string text=get_string();
    
    printf("ciphertext: ");
    int j=0;    // use to access the individual key characters
    
    // encrypt the plaintext using vigenere cipher
    for(int i=0,n=strlen(text);i<n;i++)
    {
        // if charcter in the plaintext is alphabet then encrypt
        if(isalpha(text[i]))
        {
            if(j>=length)
                j=0;
            if(isupper(text[i]))
            {
                int t=(int)text[i]-65;
                t=((t+key[j++])%26)+65;
                printf("%c",(char)t);
            }
            else if(islower(text[i]))
            {
                int t=(int)text[i]-97;
                t=((t+key[j++])%26)+97;
                printf("%c",(char)t);
            }
        }
        // if character in the plaintext is not alphabet print the same
        else
            printf("%c",text[i]);
    }
    printf("\n");
}
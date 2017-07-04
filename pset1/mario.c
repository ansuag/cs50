#include <stdio.h>
#include<cs50.h>
int main(void)
{
    int height;
    // asks user input until value between 0 and 23 is given
    do
    {
    printf("Height: " );
    height=get_int();
    }while(height>23 || height<0);
    
    // initial hash to be printed
    int hash=1;
    // initial space to be printed for aligning
    int space=height-hash;
    
    int hashes,alignSpace;
    while(height>0)
    {
        hashes=hash;
        alignSpace=space;
        while(alignSpace>0)
        {
            printf(" ");
            alignSpace--;
        }
        while(hashes>0)
        {
            printf("#");
            hashes--;
        }
        printf("  ");
        hashes=hash;
        while(hashes>0)
        {
            printf("#");
            hashes--;
        }
        printf ("\n");
        hash++;
        space--;
        height--;
    
    }
 
}
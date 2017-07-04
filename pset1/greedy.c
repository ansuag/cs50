#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
{
    // asks user input until a non negative value is given
    printf("O hai! How much change is powed?\n");
    float change=get_float();
    while(!(change>0.0))
    {
         printf("How much change is powed?\n");
         change=get_float();
    }
    // convert the amount to cents
    int cents=round(change*100);
    
    //counts the number of coins
    int coins=0;
    
    // counts number of quarters be given 
    while(cents>=25)
    {
        cents=cents-25;
        coins++;
    }
    
    //counts number of dimes be given
    while(cents>=10)
    {
        cents=cents-10;
        coins++;
    }
    
    //counts number of nickels be given
    while(cents>=5)
    {
        cents=cents-5;
        coins++;
    }
    
    //counts number of pennies be given
    while(cents>=1)
    {
        cents=cents-1;
        coins++;
    }
    
    printf("%d\n",coins);
    return 0;
}
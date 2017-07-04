#include<stdio.h>
#include<cs50.h>
int main(void)
{
   printf("Minutes: ");
   int min=get_int();
   //...1 minute shower consumes 12 bottles of water
   int bottles=min*12;
   printf("Bottles: %d\n",bottles);
}
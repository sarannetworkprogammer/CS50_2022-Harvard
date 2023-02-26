#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("what is the height = ? ");
    }
    while(height < 1 || height > 8);

// atleast it should take once input and condition has to be verified for that we use do while loop always there will be input validation

   for(int i=0; i < height; i++)

   {
       // for loop for printing spaces
       for(int k =0;k <(height -(i+1));k++)
       {
           printf(" ");
       }
       for(int j=0;j<i+1; j++)
       {
           printf("#");
       }
        printf("\n");

   }
}
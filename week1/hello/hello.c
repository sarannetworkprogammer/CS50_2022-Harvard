#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

//void swap(int x, int y);


/*int main(void)

{
    printf("hello world\n");

    string name = get_string("whats your name? ");
    printf("hello , %s\n", name);
}

*/


typedef struct node
{

    int number;
    struct node *next;
}
node;

int main(void)
{

node *list = NULL;

node *n = malloc(sizeof(node));

if (n == NULL)
{
    free(n);
    return 1;
}

n -> number = 1;

n ->next = NULL;


list = n;


}



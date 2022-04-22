#include <stdio.h>
typedef struct test
{
    int a;
    char c;

}T;

int main()
{
    T *k, b;//creating pointer to a structure variable
    k = &b;
    printf("Enter an integer:");//taking input
    scanf("%d", &k->a);
    printf("\nEnter a character:");
    scanf(" %c", &k->c);
    
    printf("\n integer:\t%d", k->a);//giving output
    printf("\n character:\t%c", k->c);
    return 0;
}
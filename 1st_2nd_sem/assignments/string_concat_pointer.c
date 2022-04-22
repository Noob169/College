
#include <stdio.h>
int main()
{
    int c=0;
    char ar1[50], ar2[50];
    char *p1=ar1, *p2=ar2;
    printf("Enter the two strings, 1  and 2, in order\n");
    gets(ar1);
    fflush(stdin);
    gets(ar2);
    
   while(*p1)
   p1++;

   while(*p2)
   {
       *p1=*p2;
        p2++;
        p1++;
   }
   *p1 = '\0';
   printf("\nConcatenated String\t%s", ar1);
    
    

}
#include <stdio.h>

 struct student
{
    char name[10];
};

int main()
{
    struct student k[5];
    printf("Enter the names\n");
    for (int i = 0; i < 5; i++)
    {
        
        printf("\nEnter name %d",(i+1));
        scanf("%s", &k[i].name);
    }
     for (int i = 0; i < 5; i++)
     {
         printf("%s\n", k[i].name);
     }
    return 0;
}
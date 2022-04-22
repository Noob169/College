#include <stdio.h>

 typedef struct student
{
    char sec;
    int roll;
    
    int marks;
}S;

int main()
{
    S k[5];
    
    
    int m=0, j=0;
    printf("Enter the data\n");
    for (int i = 0; i < 5; i++)
    {
        
        
        printf("\nEnter roll of student %d",(i+1));
        scanf("%d", &k[i].roll);
         
         printf("\nEnter marks of student %d",(i+1));
        scanf("%d", &k[i].marks);
        printf("\nEnter sec of student %d",(i+1));
        scanf(" %c", &k[i].sec);
    }
     for (int i = 0; i < 5; i++)
     {
        if(k[i].marks>m)
        {
            j = i;
            m = k[i].marks;
        }

     }
    printf("\nThe student having the highest marks is:");
    printf("\n roll: of student %d",k[j].roll);
    printf("\n sec of student: %c",k[j].sec);
    printf("\n Highest marks: %d",m);
   
    return 0;
}
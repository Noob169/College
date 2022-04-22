#include <stdio.h>
#include <string.h>
//void edit(int );
void display(int );

typedef struct student
{
    int roll;
    char name[50];
    double fee;
    int dob;
}S;

S ar[100];

int main()
{
    int n, i, eroll=0, k=0, ed=0,chr=0;
    char ch;
    printf("Enter the number of students:\n");
    scanf("%d", &n);
    
    printf("\nEnter the deatils of the students:");
    for(i=0;i<n;i++)
    {
        printf("\nEnter the roll no. of the student:\t");
        scanf("%d", &ar[i].roll);
        printf("\nEnter the name of the student:\t");
        fflush(stdin);
        gets(ar[i].name);
        printf("Enter the fee");
        printf("\nEnter the fee of the student:\t");
        scanf("%lf",&ar[i].fee);
        printf("\nEnter the date of birth in DD/MM/YYYY format:\t");
        scanf("%d", &ar[i].dob);
    }
        printf("\nEnter the roll no. of the sudent whose details you want to change:\t");
        scanf("%d", &eroll);
        for(i=0;i<n;i++)
        {
             if(eroll==ar[i].roll)
           { 
            //edit(ed);
            printf("\nEdit choices: Enter 1 for roll no, 2 for name, 3 for fee, and 4 for dob:\t");
            scanf("%d", &chr);
            
             if(chr==1)
            {
                printf("\nEnter the new roll no:\t");
                scanf("%d", &ar[ed].roll);
            }
        

            

            else if(chr==2)
           {
               printf("\nEnter the new name:\t");
               fflush(stdin);
               gets(ar[ed].name);
            }
        
            else if(chr == 3)
            {
                printf("\nEnter the new fee:\t");
                scanf("%lf", &ar[ed].fee);
            }
            
            else if(chr== 4)
            {
                printf("\nEnter the new dob, in DD/MM/YYYY format:\t");
                scanf("%d", &ar[ed].dob);
            }
            
        
            else
            printf("\nEnter a valid input");
        }
         /*if(k==1)
        {
            //edit(ed);
            printf("\nEdit choices: Enter 1 for roll no, 2 for name, 3 for fee, and 4 for dob:\t");
            scanf("%d", &chr);
            
             if(chr==1)
            {
                printf("\nEnter the new roll no:\t");
                scanf("%d", &ar[ed].roll);
            }
        

            

            else if(chr==2)
           {
               printf("\nEnter the new name:\t");
               fflush(stdin);
               gets(ar[ed].name);
            }
        
            else if(chr == 3)
            {
                printf("\nEnter the new fee:\t");
                scanf("%lf", &ar[ed].fee);
            }
            
            else if(chr== 4)
            {
                printf("\nEnter the new dob, in DD/MM/YYYY format:\t");
                scanf("%d", &ar[ed].dob);
            }*/
            
        
           
            
        }
        
    display(n);
    
}

/*void edit(int ed)
{
    int chr;
        printf("\nEdit choices: Enter 1 for roll no, 2 for name, 3 for fee, and 4 for dob:\t");
        scanf("%d", &chr);
        switch (chr)
        {
        case 1:
            printf("\nEnter the new roll no:\t");
            scanf("%d", &ar[ed].roll);
            break;

        case 2:
            printf("\nEnter the new name:\t");
            fflush(stdin);
            gets(ar[ed].name);
            break;
        
        case 3:
            printf("\nEnter the new fee:\t");
            scanf("%lf", ar[ed].fee);
            break;
        
        case 4:
            printf("\nEnter the new dob, in DD/MM/YYYY format:\t");
            scanf("%d", ar[ed].dob);
            break;
        
        default:
            break;
        }
    
}*/

void display(int n)
{
    int dd, dm, dy;
    
    for(int i=0;i<n;i++)
    {
        dd = ar[i].dob/1000000;
        dm = (ar[i].dob/10000)%100;
        dy =  ar[i].dob%10000;
        printf("\n The roll no. of the student:\t%d",ar[i].roll);
        printf("\nThe name of the student:\t");
        puts(ar[i].name);
        printf("\nThe fee:\t%lf", ar[i].fee);
        printf("\nThe date of birth in DD/MM/YYYY format:\t%d/%d/%d",dd, dm, dy);  
     }
}



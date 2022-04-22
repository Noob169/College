#include <stdio.h>
#include <string.h>

int s=0;

int produce(char buffer[][12], int counter)
{
    FILE *fp;
    printf("\nEnter the filename to create: ");
    fgets(stdin,12,buffer[counter]);
    fflush(stdin);
    fp = fopen (buffer[counter], 'w');
    fclose(fp);
    counter++;
    return counter;
}

int consume(char a[][12], int counter)
{
    printf("\nEnter the filename to delete: ");
    char file_name[12];
    fgets(stdin,12,file_name);
    if(remove(file_name)==0)
        printf("\nFile has been deleted");
    else
        printf("\nUnable to delete file");
    for(int i=0;i<counter;i++)
    {
        
    }
}

int main()
{
    int choice,counter=0;
    char buffer[5][12];
    printf("Press 1 to Produce\n2 to Consume\n3 to exit\nEnter your choice: ");
    scanf("%d",&choice);
    while(choice!=3)
    {
        switch(choice)
        {
            case 1:
                counter=produce(buffer,counter);
                break;
            case 2:
                counter=(buffer,counter);
                break;
            default:
                break;

        }
        printf("Press 1 to Produce\n2 to Consume\n3 to exit\nEnter your choice: ");
    }
}
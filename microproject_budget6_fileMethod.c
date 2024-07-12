//A program for personal budget management using files

#include <stdio.h>
int main()
{
    FILE *fpin,*fpex,*fpin_name,*fpex_name;
    int choice,numin,numex,i,inc,exp,each_in,each_ex,sum_in=0,sum_ex=0;
    char character,income_name[50],expense_name[50];
    do
    {
        printf("\n");

        //Displaying menu
        printf("Which task do you want to perform ? : \n");
        printf("1. Add income\n");
        printf("2. Add expense\n");
        printf("3. View all incomes\n");
        printf("4. View all expenses\n");
        printf("5. View budget report\n");
        printf("6. Exit\n");

        //Asking user's choice
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            fpin=fopen("income.txt","a");

            //Checking for error in opening file
            if(fpin==NULL)
            {
                printf("Error opening income amount file for writing.");
                return 1;
            }
            fpin_name=fopen("income_name.txt","a");
            if(fpin_name==NULL)
            {
                printf("Error opening income name file for writing.");
                return 1;
            }
            
            printf("\n");
            printf("Enter number of incomes : ");
            scanf("%d",&numin);

            //Entering incomes from the user
            for(i=1;i<=numin;i++)
            {
                printf("Enter income name : ");
                scanf("%s",income_name);
                fprintf(fpin_name,"%s\n",income_name);
                printf("Enter income amount : ");
                scanf("%d",&inc);
                fprintf(fpin,"%d\n",inc);
            }
            fclose(fpin);
            fclose(fpin_name);
            break;

            case 2:
            fpex=fopen("expense.txt","a");

            //Checking for error in opening file
            if(fpex==NULL)
            {
                printf("Error opening expense amount file for writing.");
                return 1;
            }
            fpex_name=fopen("expense_name.txt","a");
            if(fpex_name==NULL)
            {
                printf("Error opening expense name file for writing.");
                return 1;
            }
            
            printf("\n");
            printf("Enter number of expenses : ");
            scanf("%d",&numex);
            
            //Entering expenses from the user
            for(i=1;i<=numex;i++)
            {
                printf("Enter expense name : ");
                scanf("%s",expense_name);
                fprintf(fpex_name,"%s\n",expense_name);
                printf("Enter expense amount : ");
                scanf("%d",&exp);
                fprintf(fpex,"%d\n",exp);
            }
            fclose(fpex);
            fclose(fpex_name);
            break;

            //Case 3 is for displaying all the incomes with title
            case 3:
            printf("\n");
            fpin=fopen("income.txt","r");
            if(fpin==NULL)
            {
                printf("Error opening income amount file for reading.");
                return 1;
            }
            fpin_name=fopen("income_name.txt","r");
            if(fpin_name==NULL)
            {
                printf("Error opening income name file for reading.");
                return 1;
            }
            
            printf("INCOMES\n");
            while((fscanf(fpin,"%d",&inc)!=EOF)&&(fscanf(fpin_name,"%s",income_name)!=EOF))
            {
                printf("%s = %d\n",income_name,inc);
            }
            fclose(fpin);
            fclose(fpin_name);
            break;
            
            //Case 4 is for displaying all the expenses with title
            case 4:
            printf("\n");
            fpex=fopen("expense.txt","r");
            if(fpex==NULL)
            {
                printf("Error opening expense amount file for reading.");
                return 1;
            }
            fpex_name=fopen("expense_name.txt","r");
            if(fpex_name==NULL)
            {
                printf("Error opening expense name file for reading.");
                return 1;
            }

            printf("EXPENSES\n");
            while((fscanf(fpex,"%d",&exp)!=EOF)&&(fscanf(fpex_name,"%s",expense_name)!=EOF))
            {
                printf("%s = %d\n",expense_name,exp);
            }
            fclose(fpex);
            fclose(fpex_name);
            break;

            //Case 5 is for generating budget report
            case 5:
            fpin=fopen("income.txt","r");
            if(fpin==NULL)
            {
                printf("Error opening file for reading.");
                return 1;
            }

            //Calculating sum of all incomes
            while((fscanf(fpin,"%d",&each_in))!=EOF)
            {
                sum_in = sum_in + each_in;
            }
            printf("\n");
            printf("BUDGET REPORT\n");
            printf("Total income till date = %d\n",sum_in);
            fclose(fpin);

            fpex=fopen("expense.txt","r");
            if(fpex==NULL)
            {
                printf("Error opening file for reading.");
                return 1;
            }

            //Calculating sum of all expenses
            while((fscanf(fpex,"%d",&each_ex))!=EOF)
            {
                sum_ex = sum_ex + each_ex;
            }
            printf("Total expense till date = %d\n",sum_ex);
            fclose(fpin);

            //Calculating the savings
            printf("Savings = %d\n",sum_in-sum_ex);
            break;

            //Empty case for exiting from menu
            case 6:
            break;

            default :
            printf("Invalid choice");
        }
        printf("\n");
        printf("Do you want to continue (y/n) ? : ");
        scanf(" %c",&character);
    }while(character=='y'||character=='Y');

    return 0;
}  